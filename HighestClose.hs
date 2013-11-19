import qualified Data.ByteString.Lazy.Char8 as L

path2maximum path = do
  contents <- L.readFile path
  print $ contents2maxium contents
               
contents2maxium = maximum . map line2Int . L.lines
line2Int = price2Int . (!!3) . L.split ','

price2Int price = case L.readInt price
                       of Nothing -> Nothing
                          Just (yuan, fen) -> case L.readInt fen
                                              of Nothing -> Just $ yuan * 100
                                                 Just (fen, _) -> Just $ yuan * 100 + fen