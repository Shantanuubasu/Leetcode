class Solution:
    def subtractProductAndSum(self, n: int) -> int:
        pro=1
        sum=0
        while n!=0:
            x=n%10
            n=int (n/10)
            pro*=x
            sum+=x
        return pro-sum
#-----------------------------------------------------------------------
''' 1. we store the last digit of n in x and remove the last digit by dividing n by 10.
2. Then we multiply pro with x and add sum and x.
3. Finally, return pro-sum. '''
