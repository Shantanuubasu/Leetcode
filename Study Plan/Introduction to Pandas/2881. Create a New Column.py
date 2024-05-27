import pandas as pd

def createBonusColumn(employees: pd.DataFrame) -> pd.DataFrame:
    employees['bonus']=2*employees['salary']
    return employees

#--------------------------------------------------------------------------
#1. Just create a employee bonus column and assign 2*salary to it.
