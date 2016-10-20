-- Given a string that represents Reverse Polish Notation
-- calculate the arithmatic expression that corresponds to it
import           Data.List

calculate :: String -> String
calculate = show . head . foldl foldingFunc [] . words
    where
         foldingFunc (x:y:ys) "*" = (x * y):ys
         foldingFunc (x:y:ys) "/" = (y / x):ys
         foldingFunc (x:y:ys) "+" = (x + y):ys
         foldingFunc (x:y:ys) "-" = (y - x):ys
         foldingFunc (x:y:ys) "^" = (y ** x):ys
         foldingFunc xs numberStr = read numberStr:xs

main :: IO()
main = print (read $ calculate "10 4 3 + 2 * -" :: Float)
