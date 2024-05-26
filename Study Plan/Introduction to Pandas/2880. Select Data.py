import pandas as pd

def selectData(students: pd.DataFrame) -> pd.DataFrame:
    return students.loc[students["student_id"]==101, ['name','age']]

#--------------------------------------------------------------------------------
# 1. Use the loc and give parameters as the condition and the required columns.
