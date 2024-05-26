import pandas as pd

def selectFirstRows(employees: pd.DataFrame) -> pd.DataFrame:
    return employees.iloc[0:3]

#---------------------------------------------------------------------------
""" 1. We will use iloc to get the rows from 0 to 3.
2. Alternatively, use can also use heaad function to get the first three rows as employees.head(3). """
