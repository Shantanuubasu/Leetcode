class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        ios_base::sync_with_stdio(false);        

        int dist=INT_MAX;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==target && dist>abs(start-i)){
                dist=abs(start-i);
            }
        }

        return dist;
    }
};

//---------------------------------------------------------------------
/* 1. Start iterating in the array and update the dist if element is same as target and lesser than previous dist.
2. Finally return dist. */
