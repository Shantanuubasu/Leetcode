class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        ios_base::sync_with_stdio(false);
        unordered_map<int,int> mp;
        for(int i=0; i<nums.size(); i++){
            if(mp.find(target-nums[i])!=mp.end()){
                return {mp[target-nums[i]],i};
            }
            mp[nums[i]]=i;
        }

        return {};
    }
};

//----------------------------------------------------------------------
/* 1. We will make every element to its index.
2. We will check if the number required to complete the target is present in the map or not.
3. If found, we will return their indexes.
4. Otherwise return empty vector. */
