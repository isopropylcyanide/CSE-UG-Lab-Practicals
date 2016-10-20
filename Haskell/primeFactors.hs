import           Data.List

main :: IO ()
main = getContents >>= mapM_ (print. (\[m, l] -> numOfDivisors (gcd m l)). map read. words). tail. lines

numOfDivisors :: Integer -> Integer
numOfDivisors n =  product. map (\x -> genericLength x+1). group. factorize $ n

factorize :: Integer -> [Integer]
factorize = factorize1 2
  where
    factorize1 k m
      | k*k > m        = if m == 1 then [] else [m]
      | m `rem` k == 0 = k: factorize1 k (m `div` k)
      | otherwise      = factorize1 (k+1) m
