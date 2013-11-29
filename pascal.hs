-- 开方廉隅表 有人说开方廉隅表指的是第一类斯特林数，那斯特林数是什么？
-- 造表法可以解决很多问题
pascal = [1] : map (desc . (0 :)) pascal where
        desc [x] = [x]
        desc (x:xs@(y:_)) = (x + y) : desc xs
        