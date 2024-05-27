import pandas as pd

def fillMissingValues(products: pd.DataFrame) -> pd.DataFrame:
    products['quantity']=products['quantity'].fillna(0)
    return products

#-----------------------------------------------------------------------
# 1. Use pandas inbuilt function fillna to replace all the null values in the column with desired value.
