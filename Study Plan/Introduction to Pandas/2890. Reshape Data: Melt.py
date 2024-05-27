import pandas as pd

def meltTable(report: pd.DataFrame) -> pd.DataFrame:
        return pd.melt(report,id_vars=['product'],var_name='quarter',value_name='sales')

#---------------------------------------------------------------------------------------------
# 1. Use melt function of pandas and give parameters as id_vars, var_name and value_name.
