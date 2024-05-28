class Solution {
public:
    int mySqrt(int x) {
        ios_base::sync_with_stdio(false);

        int low=0,high=x;
        
        while(low<=high){
            int mid=(low+high)/2;

            if((long)mid*mid==(long)x){
                return mid;
            }
            else if((long)mid*mid<(long)x){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }

        return round(high);
    }
};

//-------------------------------------------------------------------
/* 1. We will use binary search, if square of mid is equal to x then return mid.
2. If square of mid is less than x, then update low to mid+1.
3. Else update high to mid-1.
4. If we do not get an answer after while loop ends then we will return high, because this is a case of a number which is not a perfect sqaure so its answer will be round off high. */
