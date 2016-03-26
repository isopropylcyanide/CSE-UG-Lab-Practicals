-- Day 22 = BST
data Tree = Empty
          | Node Int Tree Tree
            deriving Show

insert :: Tree -> Int -> Tree
insert Empty        x             = Node x Empty Empty
insert (Node y l r) x | x <= y    = Node y (insert l x) r
                      | otherwise = Node y l (insert r x)

inorder :: Tree -> IO()
inorder Empty = return ()
inorder (Node a l r) = do
        print a
        inorder l
        inorder r

myArr :: [Int]
myArr = [3,1,5,7]

height :: Tree -> Int
height Empty = 0
height (Node _ l r) = max (height l) (height r) + 1

main :: IO()
main = do
        arr <- getContents
        print $ height $  foldl insert Empty $ map (read ::String -> Int) . drop 1 $ lines arr
