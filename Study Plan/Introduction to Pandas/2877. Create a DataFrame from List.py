import pandas as pd

def createDataframe(student_data: List[List[int]]) -> pd.DataFrame:
    return pd.DataFrame(student_data,columns=['student_id','age'])


#-----------------------------------------------------------------------------
# 1. Use pandas inbuilt function DataFrame, give parameters as data and column names.
