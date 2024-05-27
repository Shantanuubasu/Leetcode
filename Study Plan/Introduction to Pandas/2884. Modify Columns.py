import pandas as pd

def modifySalaryColumn(employees: pd.DataFrame) -> pd.DataFrame:
    employees['salary']=2*employees['salary']
    return employees

#------------------------------------------------------------------------------------------
# 1. Just assign the values in the salary column the twice of current salary.
