import           Control.Applicative
import           Control.Monad       (replicateM)
import           Text.Printf         (printf)


sub :: Double
sub = 0.001
-- This function should return a list [area, volume].
solve :: Double -> Double-> [Double] -> [Double] -> [Double]
solve l r a b =
      if l <= r
        then zipWith (+) [area l r a b, volume l r a b] (solve (l + sub) r a b)
      else [0,0]

area :: Double -> t -> [Double] -> [Double] -> Double
area l _ a b = sum (zipWith(*) (zipWith( ** ) (cycle (replicate 1 l)) b) a) * sub

volume :: Double -> t -> [Double] -> [Double] -> Double
volume l _ a b = pi*( sum (zipWith(*) (zipWith( ** ) (cycle (replicate 1 l)) b) a) ** 2 )* sub



--Input/Output.
main :: IO ()
main = do
    a <-  replicateM 3 (map (read :: String -> Double) . words <$> getLine)
    mapM_ (printf "%.1f\n") $ solve (head $ last a) (last $ last a) (head a) (a !! 1)














-- END
