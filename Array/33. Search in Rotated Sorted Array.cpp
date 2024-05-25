class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low=0,high=nums.size()-1;
        while(low<=high){
            int mid=(low+high)/2;

            if(nums[mid]==target){
                return mid;
            }

            if(nums[low]<=nums[mid]){
                if(nums[low]<=target && target<=nums[mid]){
                    high=mid-1;
                }
                else{
                    low=mid+1;
                }
            }
            else{
                if(nums[mid]<=target && target<=nums[high]){
                    low=mid+1;
                }
                else{
                    high=mid-1;
                }
            }
        }

        return -1;
    }
};

//---------------------------------------------------------------------
/* 1. We will use binary search, if the target is found at the mid position return mid.
2. If not then check what part of the array is sorted.
3. Lets say left is sorted then we will check if the target lies between low and mid, if yes then make high as mid-1. Otherwise, make low as mid+1.
4. If the right part is sorted then check if target lies between mid and high if yes then update low to mid+1. Otherwise update high to mid-1.
5. If not found return -1. */
