import pandas as pd

def concatenateTables(df1: pd.DataFrame, df2: pd.DataFrame) -> pd.DataFrame:
    return pd.concat([df1,df2])

#---------------------------------------------------------------------------------------
# 1. Use concat function of pandas to concatenate two dataframes.

