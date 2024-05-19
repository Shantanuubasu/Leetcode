class Solution {
public:
    int binarysearch(vector<int> &nums, int low, int high, int target){
        while(low<=high){
            int mid=(low+high)/2;

            if(nums[mid]==target){
                return mid;
            }
            else if(target<nums[mid]){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }

        return -1;
    }

    int search(vector<int>& nums, int target) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);

        return binarysearch(nums,0,nums.size()-1,target);
    }
};

//------------------------------------------------------------------
/* 1. In binary search, we first find the mid index.
2. Then if element at mid is equal to target then we return its index.
3. If the target is less than the mid element then we make high as mid-1.
4. If target is greater than the mid element we make low as mid+1.
5. If not found then we return -1. */
