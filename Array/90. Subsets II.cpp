class Solution {
public:
    void solve(vector<int> &nums, vector<int> &v, vector<vector<int>> &ans, int idx){
        ans.push_back(v);
        for(int i=idx; i<nums.size(); i++){
            if(i>idx && nums[i]==nums[i-1]){
                continue;
            }
            v.push_back(nums[i]);
            solve(nums,v, ans, i+1);
            v.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        vector<int> v;

        solve(nums, v, ans, 0);

        return ans;
    }
};

//-------------------------------------------------------------------------
/* 1. We will first sort the nums array, so that it is easier to identify duplicates.
2. In solve(), we will push v into ans array.
3. For each element we have two choices that is to include it in the subset or exclude it.
4. First we will include it and take that subset and call solve() again.
5. Then we will exclude it from the subset.
6. If i>idx and the current element is same as last element then we skip it because we don't want duplicates.
7. Finally, return ans. */
