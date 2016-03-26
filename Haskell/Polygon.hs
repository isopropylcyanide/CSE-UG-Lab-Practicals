import           Data.List
import           Data.Tuple
type Point = (Double, Double)

stringToTuple :: String -> Point
stringToTuple s = (read (head $ words s) :: Double, read (last $ words s) :: Double)

-- Perimeter --------------------
distance :: Floating a => ((a, a), (a, a)) -> a
distance ((a, b), (c, d)) = sqrt ((d  - b) **2 + (c - a) **2)

computePerimeter :: [Point] -> Double
computePerimeter c = sum $ fmap distance (zip c (tail c) `mappend` zip [last c] [head c])


-- Area --------------------
computeArea :: [Point] -> Double
computeArea c = abs $ sum (fmap perpendDotProd (zip c (tail c) `mappend` zip [last c] [head c])) / 2.0

perpendDotProd  :: Floating a => ((a, a), (a, a)) -> a
perpendDotProd ((a, b), (c, d)) = a * d - (b * c)


-- Concavity --------------------

hull :: [Point] -> [Point]
hull l = filterPoints (orderByPolarAngle (findStart l) l)

filterPoints :: [Point] -> [Point]
filterPoints (x:y:z:xs)
    | ccw x y z = x : filterPoints (y : z : xs)
    | otherwise = x :  filterPoints (z : xs)
filterPoints x = x

ccw :: Point -> Point -> Point -> Bool
ccw (x1, y1) (x2, y2) (x3, y3) = (x2 - x1)*(y3 - y1) - (y2 - y1)*(x3 - x1) >= 0

orderByPolarAngle :: Point -> [Point] -> [Point]
orderByPolarAngle p = sortBy (polarAngleCompare p)
    where polarAngleCompare f p1 p2 = compare (polarAngle f p1) (polarAngle f p2)
          polarAngle (x1, y1) (x2, y2) = (y2-y1)/(x2-x1)

findStart :: [Point] -> Point
findStart = swap . minimum . fmap swap

isConvex ::  [Point] -> Bool
isConvex c = and $ fmap (`elem` hull c) c

main :: IO()
main = do
    arr <- getContents
    let c = fmap stringToTuple . drop 1 $ lines arr
    if isConvex c
        then putStrLn "NO"
        else putStrLn "YES"
