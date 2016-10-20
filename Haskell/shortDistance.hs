-- Given a road system consisting of roads in left right and cross over section (in triples), calculate the shortest distance
import           Control.Monad
import           Data.List

-- represents our section
data Section = Section {getA :: Int, getB :: Int, getC :: Int } deriving Show
type RoadSystem = [Section]

-- Path denotes the label it is and int is the distance
data Label = A | B | C deriving Show
type Path = [(Label,Int)]

-- represents a given RoadSystem
heathToLondon :: RoadSystem
heathToLondon = [Section 50 10 30, Section 5 90 20, Section 40 2 25, Section 10 8 0]

-- calculate optimal way to reach either cross section given a section. Can be used as a binary function with fold the two paths represent the best way to reach both A and B sections
roadStep :: (Path, Path) -> Section -> (Path , Path)
roadStep (pathA, pathB) (Section a b c) =
    --calc total best sum on path A and B so far
    let bestA = sum $ map snd pathA
        bestB = sum $ map snd pathB
        fwdA = bestA + a
        crossA = bestB + b + c
        -- The best way to reach new A is the min of
        -- fwdA or crossA
        fwdB = bestB + b
        crossB = bestA + a +  c
        newPathA = if fwdA <= crossA
                    then (A,a) : pathA
                    else (C,c) : (B,b) : pathB
        newPathB = if fwdB <= crossB
                    then (B,b) : pathB
                    else (C,c) : (A,a) : pathA
    in (newPathA, newPathB)


-- calculates optimalPath given the entire roadSystem
optimalPath :: RoadSystem -> Path
optimalPath roadSystem =
    let (bestA, bestB) = foldl roadStep ([],[]) roadSystem
    in
    if sum (map snd bestA) <= sum (map snd bestB)
        then reverse bestA
        else reverse bestB


--Split lists into groupsOf n
groupsOf :: Int -> [a] -> [[a]]
groupsOf 0 _ = undefined
groupsOf _ [] = []
groupsOf n xs = take n xs : groupsOf n (drop n xs)



-- Read input, produce a roadSystem and show the optimalPath
main :: IO()
main = do
    contents <- getContents
    let threes = groupsOf 3 (map read $ lines contents)
        roadSystem = map(\[a,b,c] -> Section a b c) threes
        path = optimalPath roadSystem
        pathString = concatMap (show . fst) path
        pathPrice = sum $ map snd path
    putStrLn $ "Optimal path: " ++ pathString
    putStrLn $ "Price is: " ++ show pathPrice
























--END
