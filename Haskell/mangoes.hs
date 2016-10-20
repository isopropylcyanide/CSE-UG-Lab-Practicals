import           Control.Monad
import           Data.List

findMaxPeople :: Int -> Int -> [Int] -> [Int] -> Int
findMaxPeople n m a h
    | minimum a > m = 0
    | otherwise = binarySearch 1 n
        where
            binarySearch l r
                | l == r = l
                | mangoes > m = binarySearch l $ mid - 1
                | mangoes <= m = binarySearch mid r
                | otherwise = undefined
                where
                    mid = div (l + r + 1) 2
                    mangoes = sum. take (fromIntegral mid). sort. zipWith (\x y -> x + (mid-1)*y)  a $ h

main :: IO()
main = do
    inp <- getLine
    let [nFriends, mangoes] = map (read :: String -> Int) $ words inp
    a <- liftM (map read . words) getLine :: IO [Int]
    h <- liftM (map read . words) getLine :: IO [Int]
    print $ findMaxPeople nFriends mangoes a h
