class Solution:
    def smallestEvenMultiple(self, n: int) -> int:
        if n%2==0:
            return n
        return n*2
#-------------------------------------------------------------------
"""1. If n is divided by 2 then return n.
2. else we return n*2. """
