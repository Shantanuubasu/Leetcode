class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int low=0,high=nums.size();

        while(low<=high){
            int mid=(low+high)/2;

            int i=lower_bound(nums.begin(),nums.end(),mid)-nums.begin();
            int c=nums.size()-i;
            if(c==mid){
                return mid;
            }
            else if(c>mid){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }

        return -1;
    }
};

//-----------------------------------------------------------------------------------
/* 1. First we will sort the array.
2. Then we will apply binary search to it.
3. We will obtain the lower bound after the mid, meaning the next greatest element after mid.
4. We will get the count of all the numbers greater than or equal to mid.
5. If count is equal to mid then return mid.
6. If count is greater than mid update low to mid+1.
7. Else, update high to mid-1.
8. If none of the numbers are found then return -1. */
