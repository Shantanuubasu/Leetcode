class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        ios_base::sync_with_stdio(false);

        int low=0,high=nums.size()-1,ans=nums.size();

        while(low<=high){
            int mid=(low+high)/2;

            if(nums[mid]==target){
                return mid;
            }
            else if(target<nums[mid]){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }

        return ans;
    }
};

//-----------------------------------------------------------------------
/* 1. We will use binary search, so if the target value is found then we return its index which will be mid.
2. If target is less than mid element that means mid can be the position at which we can insert the target so we store mid in ans and update high as mid-1.
3. If target is greater than mid element then we update low to mid+1.
4. Finally return ans. */
