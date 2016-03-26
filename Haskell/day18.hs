
import           Control.Monad
import           Data.List

isPalindrome :: String -> Bool
isPalindrome str = reverse str == str

main :: IO()
main = do
    inp <- getLine
    let truth = head . map isPalindrome $ words inp
    if truth
        then  putStrLn $ "The word, " ++ inp ++ ", is a palindrome."
        else  putStrLn $ "The word, " ++ inp ++ ", is not a palindrome."
