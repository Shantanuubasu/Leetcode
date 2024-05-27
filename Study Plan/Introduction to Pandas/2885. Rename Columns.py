import pandas as pd

def renameColumns(students: pd.DataFrame) -> pd.DataFrame:
    dict={'id':'student_id','first':'first_name','last':'last_name','age':'age_in_years'}
    return students.rename(columns=dict)

#----------------------------------------------------------------------------------------------------
'''1. Define a dictionary with keys as the old column values and values as the new column values.
2. Use the rename method in pandas and assign column parameter as dict.'''
