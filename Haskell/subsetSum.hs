import           Control.Monad
import           Data.Array
import           Data.List

-- Given an array and an element x, find length of subarray x1 such that sum of x1 >= x
-- Otherwise -1

parseInt = read :: String -> Int
strToList = map parseInt . words
listToStr = unlines. map show

f xs index maxN s = g 1 maxN
                    where g l r
                            | s > (xs ! maxN) = -1
                            | l == r = l
                            | s <= (xs ! m) = g l m
                            | otherwise = g (m + 1) r
                                where m = (l + r) `div` 2

partial _ [] = []
partial acum (x:xs) = (acum + x) : partial (acum + x) xs

main = do
    n <- readLn :: IO Int
    s <- getLine
    _ <- readLn :: IO Int
    q <- getContents
    let a = listArray (1, n) $ partial 0 $ sortBy (flip compare) (strToList s)
    putStrLn $ listToStr $ map (f a 1 n . parseInt) (lines q)





-- END
