// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        ios_base::sync_with_stdio(false);

        int low=1,high=n;

        while(low<=high){
            long long int mid=low+ (high-low)/2;

            if(isBadVersion(mid)){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};

//-----------------------------------------------------------------------
/* 1. We will use binary search, set low as 1 and high as n.
2. Then check if mid is bad or not, if yes then we update high as mid-1.
3. Else, update low as mid+1.
4. Finally return low. */
