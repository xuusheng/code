module Bitmap
( mapbit,       
  bitmap ) where
  
import Data.Char

listSum::[Int]->Int
listSum [] = 0
listSum (x:xs) = 2^(4-x) + (listSum xs)

bitmap::[Int]->[Char]
bitmap [] = []
bitmap l = (toUpper (intToDigit (listSum (takeWhile (<5) l)))): (bitmap (map (+ (-4)) (dropWhile (<5) l)))

mapbit::[Char]->[Int]
mapbit [] = []
mapbit (x:xs) =(digitToMap x) ++ (map (+4) (mapbit xs))

digitToMap::Char->[Int]
digitToMap '0' = []
digitToMap '1' = [4]
digitToMap '2' = [3]
digitToMap '3' = [3, 4]
digitToMap '4' = [2]
digitToMap '5' = [2, 4]
digitToMap '6' = [2, 3]
digitToMap '7' = [2, 3, 4]
digitToMap '8' = [1]
digitToMap '9' = [1, 4]
digitToMap 'A' = [1, 3]
digitToMap 'B' = [1, 3, 4]
digitToMap 'C' = [1, 2]
digitToMap 'D' = [1, 2, 4]
digitToMap 'E' = [1, 2, 3]
digitToMap 'F' = [1, 2, 3, 4]