import           Control.Monad


myIntersperse :: a -> [[a]] -> [a]
myIntersperse a b
    | null b = []
    | null $ tail b  = head b
    | otherwise = head b ++ [a] ++ myIntersperse a (tail b)
main :: IO()
main = interact wordCount
        where wordCount input = show (length (lines input)) ++ "\n"
