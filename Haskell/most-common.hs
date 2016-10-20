
import           Control.Monad
import           Data.List
import           Data.Ord
import           Text.Printf

type Point = (Int, Int)

distance :: Point -> Point -> Float
distance p1 p2 = sqrt $ (**2) (x' - y')
        where x' = fromIntegral (fst p2 - fst p1)
              y' = fromIntegral (snd p2 - snd p1)

strToTuple :: [String] -> [Point]
strToTuple [] = []
strToTuple (x: xs) = (head arr, last arr) : strToTuple xs
        where arr = map (read :: String -> Int) $ words x

main :: IO()
main = do
    n <- getLine
    arr <- replicateM (read n :: Int ) getLine
    let lis = strToTuple arr

    let max_l = [minimumBy (comparing fst) lis, maximumBy (comparing fst) lis,
                maximumBy (comparing snd) lis, minimumBy (comparing snd) lis]

    printf "%.6f" (maximum [distance  p1 p2 | p1 <- max_l , p2 <- max_l, p1 /= p2])














    -- END
