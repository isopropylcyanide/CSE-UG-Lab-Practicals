
euclidGcd :: Int -> Int -> Int
euclidGcd a b
    | b == 0 = a
    | otherwise = euclidGcd b (mod a b)


quotient :: Int -> Int -> Int
quotient a b = fst $ divMod a b

extendedGCDUtil :: Int -> Int -> Int -> Int -> Int -> Int -> [Int]
extendedGCDUtil a b s1 s2 t1 t2
    | b == 0 = [s1, t1]
    | otherwise = extendedGCDUtil b (mod a b) s2 (s1 - (quo *s2)) t2 (t1 - (quo *t2))
        where quo = quotient a b


extendedGCD :: Int -> Int -> [Int]
extendedGCD a b
    | euclidGcd a b == 0 = []
    | otherwise = extendedGCDUtil a b 1 0 0 1


nums :: [Int]
nums = [3, 12, 4, 5]
mods = [5, 19, 7, 11]



main :: IO()
main = putStrLn "hi"
