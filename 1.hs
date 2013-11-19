import System.Environment
import Data.List
import Data.Char
interactWith f i o = do
input <- readFile i
	writeFile o (f input)
 

main = mainWith myFunction
       where mainWith f = do
               a <- getArgs
               case a of [i, o] -> interactWith f i o
                         _ -> putStrLn "error"
             myFunction = filter (`elem` '\n':[' '..'~'])

succ ((\(a,b)->b) (last (takeWhile (\(a,b) -> a < n) zip (map (1/) [1..]) [1..])))
