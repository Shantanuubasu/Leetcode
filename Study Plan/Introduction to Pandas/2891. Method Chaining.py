import pandas as pd

def findHeavyAnimals(animals: pd.DataFrame) -> pd.DataFrame:
    return animals[animals['weight']>100].sort_values('weight',ascending=False)[['name']]

# ---------------------------------------------------------------------------------------------------
#1. We return the names of animals with weight>100 and sort it according to descending order of weights.
