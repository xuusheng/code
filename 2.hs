primes = 2 : filter ((==1) . length . primeFactors) [3,5..]
primeFactors n = factor n primes where
	factor n (p:ps)
		|p*p > n = [n]
		|mod n p == 0 = p : factor (div n p) (p:ps)
		|otherwise = factor n ps

hamming = 1 : map (2*) hamming ~~ map (3*) hamming ~~ map (5*) hamming
	where
	xxs@(x:xs) ~~ yys@(y:ys)
		|x == y = (x:xs~~ys)
		|x > y = (y:ys~~xxs)
		|x < y = (x:xs~~yys)
		
                             

qsort :: Ord a => [a] -> [a]
qsort [] = []
qsort (x:xs) = 
  let ls = [a|a<-xs, a<x]
      rs = [a|a<-xs, a>=x]
  in qsort ls ++ [x] ++ qsort rs 

                         
lTrim :: [Char] -> [Char]
lTrim a@(x:xs)  
	|x == ' ' = lTrim xs
	|otherwise = a

rTrim :: [Char] -> [Char]
rTrim a
	|last a == ' ' = rTrim (init a)
	|otherwise = a

allTrim :: [Char] -> [Char]
allTrim = lTrim . rTrim
