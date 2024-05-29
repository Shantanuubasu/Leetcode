class Solution {
public:
    int findMin(vector<int>& nums) {
        ios_base::sync_with_stdio(false);

        int ans=nums[0];
        int low=0,high=nums.size()-1;
        while(low<=high){
            int mid=(low+high)/2;

            if(nums[low]==nums[mid] && nums[high]==nums[mid]){
                ans=min(ans,nums[mid]);
                low++;
                high--;
                continue;
            }

            if(nums[low]<=nums[mid]){
                ans=min(ans,nums[low]);
                low=mid+1;
            }
            else{
                ans=min(ans,nums[mid]);
                high=mid-1;
            }
        }

        return ans;
    }
};

//-----------------------------------------------------------------------------
/* 1. We will apply binary search to solve this problem.
2. If we get duplicates meaning same element in low, mid and high then we update ans and move low and high pointer by one.
3. If element at low is less than at mid then update ans and make low as mid+1.
4. Else, update ans and update high as mid-1.
5. Finally return ans. */
