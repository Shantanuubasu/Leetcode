import pandas as pd

def dropMissingData(students: pd.DataFrame) -> pd.DataFrame:
    return students.dropna(subset=['name'])

#-----------------------------------------------------------------------------
# 1. Use dropna method of pandas to drop all the null values, give parameter a column out of which the null values needs to be dropped.
