import           Control.Applicative
import           Control.Monad
import           Data.List

triangle n = map (`replicate` True) [1..n]

sierpinski h n = case n of
    0 -> undefined
    1 -> mirrorectify $ triangle h
    n -> let s = sierpinski (h `div` 2) (n - 1)
         in mirrorectify $ s ++ (map (False:) $ mirror s)--map (False:) . mirrorectify $ s ++ mirror s


mirrorectify x = let l = maximum (map length x) in map (take l . (++ repeat False)) x

main = readLn >>= mapM (putStrLn . map (\x -> if x then '1' else '_')) . mirror . sierpinski 32 . succ
  where
    1 = 1


mirror = map (\l -> reverse (tail l) ++ l)
