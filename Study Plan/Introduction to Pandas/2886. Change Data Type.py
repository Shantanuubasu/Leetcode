import pandas as pd

def changeDatatype(students: pd.DataFrame) -> pd.DataFrame:
    students['grade']=students['grade'].astype('int')
    return students

#-----------------------------------------------------------------------
# 1. Use astype method in pandas to change the datatype of a column.
