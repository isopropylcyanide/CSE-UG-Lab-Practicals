data Tree = Tree { value :: Int, children :: [Tree], leftRev :: [Tree], right :: [Tree], parent :: Maybe Tree }

readInt :: String -> Int
readInt = read

change x (Tree v c l r p, s) = (Tree x c l r p, s)

print_ (t@(Tree v c l r p), s) = (t, v:s)

visitLeft (t@(Tree v c ((Tree v' c' l' r' p'):ls) r p), s) = (Tree v' c' ls (t:r) p, s)

visitRight (t@(Tree v c l ((Tree v' c' l' r' p'):rs) p), s) = (Tree v' c' (t:l) rs p, s)

visitParent (t@(Tree v c l r (Just (Tree v' _ l' r' p'))), s) = (Tree v' (reverse l ++ t : r) l' r' p', s)

visitChild n (t@(Tree v c l r p), s) =
  let Tree v' c' l' r' p' = c !! n
  in (Tree v' c' (reverse (take n c)) (drop (n + 1) c) (Just t), s)

insertLeft x (t@(Tree v c l r p), s) = (Tree v c ((Tree x [] l (t:r) p):l) r p, s)

insertRight x (t@(Tree v c l r p), s) = (Tree v c l ((Tree x [] (t:l) r p):r) p, s)

insertChild x (t@(Tree v c l r p), s) = (Tree v ((Tree x [] [] c (Just t)):c) l r p, s)

delete (Tree v c l r (Just (Tree v' _ l' r' p')), s) = (Tree v' (reverse l ++ r) l' r' p', s)

getCmd = fmap parseLine getLine

parseLine s =
  case words s of
    ["change", x] -> change (readInt x)
    ["print"] -> print_
    ["visit", "left"] -> visitLeft
    ["visit", "right"] -> visitRight
    ["visit", "parent"] -> visitParent
    ["visit", "child", n] -> visitChild ((readInt n) - 1)
    ["insert", "left", x] -> insertLeft (readInt x)
    ["insert", "right", x] -> insertRight (readInt x)
    ["insert", "child", x] -> insertChild (readInt x)
    ["delete"] -> delete

main = getLine >>= (sequence . flip replicate getCmd . readInt) >>= (sequence_ . map (putStrLn . show) . reverse . snd . ($ (Tree 0 [] [] [] Nothing, [])) . foldl (flip (.)) id)
