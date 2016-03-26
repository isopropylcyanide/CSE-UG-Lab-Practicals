-- Day 11 = 2D Arrays + More review

main :: IO()
main = do
    xs <- sequence [getLine, getLine, getLine,
        getLine, getLine, getLine]
    let numbers =
         map (map (read :: String -> Int) . words )  xs
    print $ maximum (hGlassMap numbers)

hourglassSum :: [[Int]] -> [Int]
hourglassSum ([_, _] : _)  = []
hourglassSum [a, b, c] =
    (sum (take 3 a)) + (head $ tail b) + (sum (take 3 c)) :
    hourglassSum [tail a, tail b, tail c]
hourglassSum _ = []


hGlassMap :: [[Int]] -> [Int]
hGlassMap [_, _] = []
hGlassMap (a : b : c : xs) = maximum (hourglassSum [a,b,c]) : hGlassMap (b:c: xs)
hGlassMap _ = []







-- END
