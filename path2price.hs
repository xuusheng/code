import qualified Data.ByteString.Lazy.Char8 as L

path2maximum path = do
  contents <- L.readFile path
  print $ contents2maxium contents
               
contents2maxium = maximum . map line2Int . L.lines
line2Int = price2Int . (!!4) . L.split ','

price2Int price =
  case L.readInt price of
    Nothing -> Nothing
    Just (yuan, fen) -> case L.readInt (L.tail fen) of
      Nothing -> Nothing
      Just (fen, _) -> Just $ yuan * 100 + fen