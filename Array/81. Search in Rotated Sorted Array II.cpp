class Solution {
public:
    bool search(vector<int>& nums, int target) {
        ios_base::sync_with_stdio(false);
    
        int low=0, high=nums.size()-1;

        while(low<=high){
            int mid=(low+high)/2;

            if(nums[mid]==target){
                return true;
            }

            if(nums[low]==nums[mid] && nums[mid]==nums[high]){
                low+=1;
                high-=1;
                continue;
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

        return false;
    }
};

//--------------------------------------------------------------------------------
/* 1. We will use binary search, if the target is found at the mid position return mid.
2. If not then check what part of the array is sorted.
3. Lets say left is sorted then we will check if the target lies between low and mid, if yes then make high as mid-1. Otherwise, make low as mid+1.
4. If the right part is sorted then check if target lies between mid and high if yes then update low to mid+1. Otherwise update high to mid-1.
5. If the numbers at low, mid and high postion are same then we will move low forward and high backwards. 
6. If not found return -1. */
