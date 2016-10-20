import           Control.Monad
import qualified Data.Set      as Set

getDiv :: Integral a => a -> [a]
getDiv n = concat [ [x, div n x] | x <- [1..round $ sqrt $ fromIntegral n] , n `mod` x == 0]


commonDiv :: Int -> Int -> Set.Set Int
commonDiv m l = Set.intersection mDiv lDiv
        where mDiv = Set.fromList $ getDiv m
              lDiv = Set.fromList $ getDiv l

solver :: (Eq r, Num r) => r -> IO ()
solver 0 = return ()
solver n = do
    a <- liftM (map read . words) getLine :: IO [Int]
    print . length . Set.foldr (:) [] $ commonDiv (head a) (a !! 1)
    solver $ n - 1

main :: IO()
main = do
    inp <- getLine
    solver (read inp :: Int)
