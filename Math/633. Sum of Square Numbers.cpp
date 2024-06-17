class Solution {
public:
    bool judgeSquareSum(int c) {
        ios_base::sync_with_stdio(false);

        long long int low=0, high=sqrt(c);
        while(low<=high){
            long long int num=(low*low) + (high*high);
            if(num==c){
                return true;
            }
            else if(num<c){
                low++;
            }
            else{
                high--;
            }

        }

        return false;
    }
};

//--------------------------------------------------------------------------------
/* 1. We will use binary search, take low as 0 and high as square root of c as the max value for search will be square root of c.
2. Now calculate sum of squares of low and high.
3. If num is equal to c then return true.
4. If num is less than c then increment low.
5. Else, decrement high.
6. IF the sum is not found then return false. */
