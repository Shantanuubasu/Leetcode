class Solution {
public:
    int binarysearch(vector<int> &nums, int low, int target, bool searchleft){
        int left=low;
        int right=nums.size()-1;
        int res=-1;
        while(left<=right){
            int mid=(left+right)/2;
            if(target<nums[mid]){
                right=mid-1;
            }
            else if(target>nums[mid]){
                left=mid+1;
            }
            else{
                res=mid;
                if(searchleft){
                    right=mid-1;
                }
                else{
                    left=mid+1;
                }
            }
        }

        return res;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        ios_base::sync_with_stdio(false);

        int left=binarysearch(nums,0,target,true);
        int right=binarysearch(nums,0,target,false);
        return {left,right};
    }
};

//--------------------------------------------------------------------------
