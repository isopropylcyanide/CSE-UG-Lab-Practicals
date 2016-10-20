

solve :: Int -> Int
solve x
    | x == 0 = 3
    | x == 1 = 1
    | x `mod` 4 == 0 = x
    | (x -3) `mod` 4 == 0 = x -1
    | otherwise = -1


main :: IO()
main = do
    t <- getContents
    putStrLn . unlines . map (show . (solve . read :: String -> Int)) . drop 1 $ lines t
