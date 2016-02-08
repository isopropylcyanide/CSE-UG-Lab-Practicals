-- Day 14 Scope

import           Control.Monad
import           Data.List

main :: IO()
main = do
    input <- getLine
    arr <- map (read :: String -> Int) . words <$> getLine
    print $ abs ( maximum arr - minimum arr)
