import           Control.Monad
import qualified Data.Map      as Map

functionCheck :: Map.Map Int Int -> Int -> String -> IO()
functionCheck m n flag
    | n == 0 = do
        putStrLn flag
        return ()
    | otherwise = do
        a <- getLine
        let line = map (read :: String -> Int) $ words a
        let result = Map.lookup (head line) m

        case result of
            Nothing  -> do
                let mA = Map.insert (head line) (line !! 1) m
                functionCheck mA (n - 1) flag
            _ -> functionCheck m (n - 1) "NO"

main :: IO()
main = do
    t <- readLn :: IO Int
    forM_ [1..t] $  \_ -> do
        n <- readLn :: IO Int
        a <- getLine
        let line = map (read :: String -> Int) $ words a
        let m = Map.insert (head line) (line !! 1) Map.empty
        functionCheck m (n - 1) "YES"
