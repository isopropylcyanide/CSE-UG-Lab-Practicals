{-# LANGUAGE BangPatterns #-}
{-# LANGUAGE MagicHash    #-}
import           Control.Applicative
import           Control.Monad
import qualified Data.ByteString.Char8        as B
import           Data.ByteString.Lazy.Builder
import qualified Data.IntMap.Strict           as M
import           Data.Maybe
import           Data.Monoid
import           Debug.Trace
import           System.IO

readIntWords = map readInt . B.words
readInt = fst . fromJust . B.readInt
--unwords_ = foldr wadd mempty
--  where wadd w1 w2 = w1 <> charUtf8 ' ' <> w2
unlines_ = foldr ladd mempty
  where ladd s1 s2 = s1 <> charUtf8 '\n' <> s2

type Army = M.IntMap Int
type Armies = M.IntMap Army

main = do
  nq <- readIntWords <$> B.getLine
  let [n,q] = nq
  qs<-map readIntWords . B.lines <$> B.getContents
  let output = solveR M.empty qs
  hPutBuilder stdout . unlines_ . map intDec $ output
  return ()

solveR !a ([1,i]:qR) = findStrongest a i : solveR a qR
solveR !a ([2,i]:qR) = solveR (strongestDied a i) qR
solveR !a ([3,i,c]:qR) = solveR (recruit a i c) qR
solveR !a ([4,i,j]:qR) = solveR (merge a i j) qR
solveR _ _ = []

findMaxSafe a | M.null a = (0,0)
              | otherwise = M.findMax a

-- findStrongest :: Armies -> Int -> String
findStrongest !armies i = c
  where a = fromMaybe M.empty $ M.lookup i armies
        (c,_) = findMaxSafe a

strongestDied !armies0 i
  | v==1 = M.insert i (M.delete c a) armies0
  | otherwise = M.insert i (M.insert c (v-1) a) armies0
  where a = fromMaybe M.empty $ M.lookup i armies0
        (c,v) = findMaxSafe a

recruit !armies0 i c = M.insert i (M.insert c (old+1) a) armies0
  where a = fromMaybe M.empty $ M.lookup i armies0
        old = fromMaybe 0 $ M.lookup c a

merge !armies0 i j = armies2
  where ai0 = fromMaybe M.empty $ M.lookup i armies0
        aj = fromMaybe M.empty $ M.lookup j armies0
        ai1 = M.unionWith (+) ai0 aj
        armies1 = M.delete j armies0
        armies2 = M.insert i ai1 armies1
