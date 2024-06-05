class Solution {
public:
    bool isPerfectSquare(int num) {
        int low=0,high=num;
        while(low<=high){
            int mid=low+(high-low)/2;

            if((long)mid*mid==num){
                return true;
            }
            else if((long)mid*mid>num){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }

        return false;
    }
};

//-----------------------------------------------------------
/* 1. We will apply binary search, take low as 0 and high as num.
2. Find mid, if mid*mid is equal to num then return true.
3. Else if mid*mid is greater than num then we need a smaller number so we update high to mid-1.
4. Else, update low as mid+1.
5. If no answer is found then return false. */
