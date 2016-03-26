-- Day 16: Sorting
import           Control.Applicative
import           Data.List

minAbsDiff :: [Int] -> [(Int, Int)] -> Int -> [(Int, Int)]
minAbsDiff [_] best _ = best
minAbsDiff (x: y: xs) best best_diff
        | abs (x - y) == best_diff = minAbsDiff (y: xs) (best ++ [(x, y)]) best_diff
        | abs (x - y) < best_diff = minAbsDiff (y: xs) [(x, y)] $ abs (x - y)
        | otherwise = minAbsDiff (y: xs) best best_diff


tupleToList :: [(Int, Int)] -> [Int]
tupleToList ((a, b) : xs) = a : b : tupleToList xs
tupleToList _ = []

main :: IO()
main = do
    _ <- getLine
    arr <- map (read :: String -> Int) . words <$> getLine
    let x = tupleToList $ minAbsDiff (sort arr) [] (maxBound :: Int)
    putStrLn . unwords $ map show  x
