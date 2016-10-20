

solve :: [String] -> Int -> Int -> Int -> Int
solve op i j moves =
    case op !! moves of
        "/" -> quot i j
        "*" -> i * j
        "+" -> i + j
        "-" -> i - j
        [] -> -1


riddleSolve :: [Int] -> [String] -> Int -> Int -> Int -> IO()
riddleSolve arr op i ans moves
    | i  >= length arr -1 = print ans
    | otherwise = do
        let newAns = solve op ans (arr !! (i +1 )) moves
        if moves == 3
            then riddleSolve arr (tail . take 5 $ cycle op) (i + 1) newAns 0
            else riddleSolve arr op (i +1) newAns (moves +1)


main :: IO()
main = do
    x <- getContents
    let arr = map (read :: String -> Int) . words. unwords.  drop 2 $ lines x
    riddleSolve arr ["/","*","+","-"] 0 (head arr) 0
