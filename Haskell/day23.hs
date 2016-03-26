-- Day 23 = BST levelOrder

-- Represent our  tree node
data Tree = Empty
          | Node Int Tree Tree
            deriving Show


-- Queue => First [] contains front of thhe Queue
-- Second [] contains the end(storing it in reverse)
data Queue  = Queue [Tree] [Tree]
                deriving Show

-- Create a new queue()
newQueue :: Queue
newQueue = Queue [] []


-- Enqueue a new item
enqueue :: Queue -> Tree -> Queue
enqueue (Queue xs ys) y = Queue xs (y:ys)

-- Dequeue element only if not empty
dequeue :: Queue -> Queue
dequeue (Queue [] []) = error "Empty Queue"
dequeue (Queue (_:xs) ys) = Queue xs ys
dequeue (Queue [] ys) = dequeue (Queue (reverse ys) [])

-- Inserts a node into tree
insert :: Tree -> Int -> Tree
insert Empty        x             = Node x Empty Empty
insert (Node y l r) x | x <= y    = Node y (insert l x) r
                      | otherwise = Node y l (insert r x)

-- Returns a new queue iff tree exists
getChild :: Queue -> Tree -> Queue
getChild q Empty = q
getChild q node = enqueue q node

-- Given a queue, perform levelOrder traversal
levelOrderUtil :: Queue -> IO()
levelOrderUtil (Queue [] []) = return ()
levelOrderUtil (Queue [] ys) = levelOrderUtil (Queue (reverse ys) [])
levelOrderUtil (Queue (x:xs) ys) = do
                    let (Node a l r) = x
                    putStr ( show a ++ " ")
                    let q = dequeue (Queue (x:xs) ys)
                    let left = getChild q l
                    let right = getChild left r
                    levelOrderUtil right


-- Gives a level order traversal using custom queues
levelOrder :: Tree -> IO()
levelOrder Empty = return ()
levelOrder treeNode = do
            let que = enqueue newQueue treeNode
            levelOrderUtil que



main :: IO()
main = do
        arr <- getContents
        let binTree = foldl insert Empty $ map (read ::String -> Int) . drop 1 $ lines arr
        levelOrder binTree





--
