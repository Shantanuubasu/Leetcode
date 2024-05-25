class Solution {
public:
    int findMin(vector<int>& nums) {
        int ans=INT_MAX;
        int low=0,high=nums.size()-1;

        while(low<=high){
            int mid=(low+high)/2;

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

//----------------------------------------------------------------
/* 1. We will implement binary search, if the element at low is less than mid then update ans and update low to mid+1. As the lowest element in this part of array is at low and now we need to check other part.
2. If not then update ans and update high as mid-1. As the lowest element of this part of array is at mid and now we check in other part of leat element.
3. Finally return ans. */
