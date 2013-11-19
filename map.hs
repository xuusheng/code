-- map (\x->f 1 x x) [5..100]
f:: Float -> Int -> Int -> Int
f m x n
  |m < 0.05 = x
  |otherwise = f (m * fromIntegral(x)/fromIntegral(n)) (x - 1) n
