-- Day 10 = Binary


convertToBin :: Int -> [Int]
convertToBin = reverse . map (`mod` 2) . takeWhile (>0) . iterate (`div` 2)

main :: IO()
main = interact $ unlines . map (concatMap show . convertToBin . read ) . drop 1 . lines
