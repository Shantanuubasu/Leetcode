import pandas as pd

def dropDuplicateEmails(customers: pd.DataFrame) -> pd.DataFrame:
    return customers.drop_duplicates(subset=['email'])

#---------------------------------------------------------------------------------------
# 1. Use drop_duplicates function of pandas to remove the duplicates, give parameter as the column that needs to be unique.
