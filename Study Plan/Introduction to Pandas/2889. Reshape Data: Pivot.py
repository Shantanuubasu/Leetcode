import pandas as pd

def pivotTable(weather: pd.DataFrame) -> pd.DataFrame:
    return pd.pivot_table(weather,index='month',columns='city',values='temperature',aggfunc='sum')

#--------------------------------------------------------------------------------------------------------------
# 1. Use pivot_table function of pandas and give parameters as the dataframe, index,columns, values and aggfunc to get the values in integer rather than float.
