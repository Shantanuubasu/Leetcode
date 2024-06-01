class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        ios_base::sync_with_stdio(false);

        int low=0,high=arr.size()-1;

        while(low<=high){
            int mid=low+(high-low)/2;
            int miss=arr[mid]-(mid+1);

            if(miss<k){
                low=mid+1;
            }
            else{
                high=mid-1;
            }

        }

        return k+high+1;
    }
};

//-----------------------------------------------------------
/* 1. We will use binary search, initialize low and high as 0 and array's size-1 respectively.
2. Calculate mid and check the number of missing numbers at mid.
3. If less than k then update low to mid+1 to find more missing numbers.
4. Else, update high to mid-1.
5. Finally return k+high+1 because high+1 indicates the number of missing elements and add k to that to find kth missing number. */
