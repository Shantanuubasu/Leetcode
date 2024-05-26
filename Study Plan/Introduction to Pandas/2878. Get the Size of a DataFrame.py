import pandas as pd

def getDataframeSize(players: pd.DataFrame) -> List[int]:
    return [players.shape[0],players.shape[1]]

#--------------------------------------------------------------------
# 1. We will use inbuilt function shape to get the no. of rows and no. of columns.
