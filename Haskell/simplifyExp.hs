import           Control.Applicative
import           Data.Char
import           Data.List
import           Data.Ratio
import           Text.ParserCombinators.ReadP

data Polynomial a = Polynomial {coefficients :: [a], maxDegree :: Int}

scale :: Num a => a -> Polynomial a -> Polynomial a
scale c (Polynomial as m) = Polynomial (map (c*) as) m

timesX :: Num a => Polynomial a -> Polynomial a
timesX (Polynomial as m) = Polynomial (0:as) (m+1)

x :: Num a => Polynomial a
x = Polynomial (0:1:repeat 0) 1

instance Num a => Num (Polynomial a) where
  fromInteger n = Polynomial (fromInteger n : repeat 0) 0
  Polynomial as m + Polynomial bs n = Polynomial (zipWith (+) as bs) (max m n)
  negate (Polynomial as m) = Polynomial (map negate as) m
  Polynomial as m * p = sum $ snd $ mapAccumL (\pxk a -> (timesX pxk,scale a pxk)) p (take (m+1) as)
  abs = undefined
  signum = undefined

(//) :: Fractional a => Polynomial a -> Polynomial a -> Polynomial a
p // (Polynomial (a:_) _) = scale (recip a) p

instance (Ord a, Num a, Show a) => Show (Polynomial a) where
  show (Polynomial as m) =
    let show0 = concat $ reverse $ take (m+1) $ zipWith f as ("1":"x":map (\k -> "x^" ++ show k) [2..])
    in  case show0 of
          "" -> "0"
          ' ':'-':' ':s -> '-':s
          ' ':'+':' ':s -> s
      where f a xk
              | a == -1 = " - " ++ xk
              | a  <  0 = " - " ++ show (abs a) ++ xk'
              | a ==  0 = ""
              | a ==  1 = " + " ++ xk
              | a  >  0 = " + " ++ show a ++ xk'
              where xk' = if xk == "1" then "" else xk

manyGreedy p = ((:) <$> p <*> manyGreedy p) <++ return []

integerP :: ReadP Integer
integerP = read <$> munch1 isDigit

exprP :: ReadP (Polynomial Rational)
atomP = (fromInteger <$> integerP)
  <++ (char 'x' *> pure x)
  <++ between (char '(') (char ')') exprP
powP = (^) <$> atomP <*> option 1 (char '^' *> integerP)
prodP = chainl1 powP ((char '*' *> pure (*)) <++ (char '/' *> pure (//)) <++ return (*))
exprP = (+) <$> (($) <$> option id (char '-' *> pure negate) <*> prodP)
            <*> (sum <$> manyGreedy (($) <$> ((char '+' *> pure id) <++ (char '-' *> pure negate))
                                         <*> prodP))

strip :: Polynomial Rational -> Polynomial Integer
strip (Polynomial as m) = Polynomial (map round as) m

parse :: String -> Polynomial Rational
parse str =
  let [(p,"")] = readP_to_S (exprP <* eof) (filter (not . isSpace) str)
  in  p

main = do
  _:exprs <- fmap lines getContents
  mapM_ (print . strip . parse) exprs
