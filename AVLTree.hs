module AVLTree where
import Test.QuickCheck
import qualified Data.List as L
data AVLTree a = Empty | Br (AVLTree a) a (AVLTree a) Int
insert::(Ord a) => AVLTree a -> a -> AVLTree a
insert t x = fst $ ins t where
  ins Empty = (Br Empty x Empty 0, 1)
  ins (Br l k r d)
	| x < k = node (ins l) k (r, 0) d
	| x == k = (Br l k r d, 0)
	| otherwise = node (l, 0) k (ins r) d

node::(AVLTree a, Int) -> a -> (AVLTree a, Int) -> Int -> (AVLTree a, Int)
node (l, dl) k (r, dr) d = balance (Br l k r d', delta) where
  d' = d + dr - dl
  delta
    |d' == 0 = 0
    |otherwise = abs(dr - dl)

balance :: (AVLTree a, Int) -> (AVLTree a, Int)
balance (Br (Br l k1 r1 (-1)) k r (-2), _) = (Br l k1 (Br r1 k r 0)  0, 0)
balance (Br l k (Br l1 k1 r 1) 2, _) = (Br (Br l k l1 0) k1 r 0, 0)
balance (Br l k (Br (Br l2 k2 r2 x) k1 r1 (-1)) 2, _) = (Br (Br l k l2 x1) k2 (Br r2 k1 r1 x2) 0, 0) where
  x1 = -div (x + abs(x)) 2
  x2 = div (abs(x)-x) 2
balance (Br (Br l1 k1 (Br l2 k2 r2 x) 1) k r (-2), _) = (Br (Br l1 k1 l2 x1) k2 (Br r2 k r x2) 0, 0) where
  x1 = -div (x + abs(x)) 2
  x2 = div (abs(x)-x) 2
balance (t, d) = (t, d)

isAVL :: (AVLTree a) -> Bool
isAVL Empty = True
isAVL (Br l _ r d) = and [isAVL l, isAVL r, d == (height r - height l), abs d <= 1]

height :: (AVLTree a) -> Int
height Empty = 0
height (Br l _ r _) = 1 + max (height l) (height r)

checkDelta :: (AVLTree a) -> Bool
checkDelta Empty = True
checkDelta (Br l _ r d) = and [checkDelta l, checkDelta r, d == (height r - height l)]

fromList::(Ord a)=>[a] -> AVLTree a
fromList = foldl insert Empty

toList :: (AVLTree a) -> [a]
toList Empty = []
toList (Br l k r _) = toList l ++ [k] ++ toList r

prop_bst :: (Ord a, Num a) => [a] -> Bool
prop_bst xs = (L.sort $ L.nub xs) == (toList $ fromList xs)

prop_delta :: (Ord a, Num a) => [a] -> Bool
prop_delta = checkDelta . fromList . L.nub

prop_avl :: (Ord a, Num a) => [a] -> Bool
prop_avl = isAVL . fromList . L.nub

instance Show a => Show (AVLTree a) where
  show Empty = "."
  show (Br l k r d) = "(" ++ show l ++ " " ++
                      show k ++ ":[" ++ show d ++ "] " ++
                      show r ++ ")"