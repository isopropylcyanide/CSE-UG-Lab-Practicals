import qualified Data.Heap     as Heap

-- Maintain a DSU along with a max Heap per index
-- findStrongest (i) returns the root of maxHeap at index i
findStrongest :: Heap.HeapItem pol item => Int -> [(a, Heap.Heap pol item)] -> Maybe item
findStrongest i vecMap = Heap.viewHead (snd (vecMap !! i))

-- strongestDied (i) removes the root and re heapifies at i
strongestDied :: Heap.HeapItem pol item => Int -> [(t, Heap.HeapT (Heap.Prio pol item) (Heap.Val pol item))] -> [(t, Heap.Heap pol item)]
strongestDied i vecMap =
    let (parent, oldHeap) = vecMap !! i
        newHeap = Heap.drop 1 oldHeap
        splitter = splitAt i vecMap
    in fst splitter `mappend` [(parent, newHeap)] `mappend` tail (snd splitter)

-- recruit (i, c) inserts c at maxHeap i and reheapfies
recruit :: Heap.HeapItem pol item => Int -> item -> [(t, Heap.HeapT (Heap.Prio pol item) (Heap.Val pol item))] -> [(t, Heap.Heap pol item)]
recruit i c vecMap =
    let (parent, oldHeap) = vecMap !! i
        newHeap = Heap.insert c oldHeap
        splitter = splitAt i vecMap
    in fst splitter `mappend` [(parent, newHeap)] `mappend` tail (snd splitter)

--merge(i, j) set parent of j as i and insert the root of j to heap i
merge :: Heap.HeapItem pol item => Int -> Int -> [(a, Heap.HeapT (Heap.Prio pol item) (Heap.Val pol item))] -> [(a, Heap.Heap pol item)]
merge i j vecMap =
    let (parent, oldHeap) = vecMap !! i
        oldLostArmyBest = Heap.toList (snd $ vecMap !! j)
        newHeap = foldr Heap.insert oldHeap oldLostArmyBest
        splitter = splitAt i vecMap
    in fst splitter `mappend` [(parent, newHeap)] `mappend` tail (snd splitter)


qParse :: Int -> [(Int,  Heap.HeapT (Heap.Prio Heap.MaxPolicy Int) ())] -> [Int] -> IO()
qParse query vecMap answers
    | query == 0 = putStr . unlines $ fmap show answers
    | otherwise = do
                    -- let q = [1,2,3]
                    q <- fmap (read :: String -> Int) . words <$> getLine
                    case head q of
                        1 -> do
                                let result = findStrongest (last q) vecMap
                                case result of
                                    Nothing -> qParse (query -1) vecMap answers
                                    _ -> let
                                        Just ans = result
                                        in qParse (query -1) vecMap (answers `mappend` [ans])

                        2 -> qParse (query -1) (strongestDied (last q) vecMap)  answers

                        3 -> qParse (query -1) (recruit (q !! 1) (q !! 2) vecMap) answers

                        _ -> qParse (query -1) (merge (q !! 1) (q !! 2) vecMap) answers



main :: IO()
main =  do
    c <- fmap (read :: String -> Int) . words <$> getLine
    let n = head c
    let queries = last c

    let h = Heap.fromList [] :: Heap.MaxHeap Int
    let vecMap = fmap (\a -> (a, h)) [0..n]

    qParse queries vecMap []
    -- forM_ [1..queries] $ \_ -> do
    --     q <- fmap (read :: String -> Int) . words <$> getLine
    --     qParse q
