import           Control.Monad

myMod :: Integer
myMod = 1000000007

main :: IO()
main = do
    _ <- getLine
    a <- liftM (map read . words) getLine :: IO [Integer]
    _ <- getLine
    b <- liftM (map read . words) getLine :: IO [Integer]
    print $ gcd (product a) (product b) `mod` myMod
