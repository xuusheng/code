fib = 0:1:zipWith (+) fib (tail fib)
main = do
  putStrLn $ show $last $take 10000 fib
