class Solution {
public:
    void subset(int j, vector<int> &nums, vector <int>&v, vector<vector<int>> &ans){
        ans.push_back(v);
        for(int i=j; i<nums.size(); i++){
            v.push_back(nums[i]);
            subset(i+1,nums,v,ans);
            v.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> v;
        subset(0,nums,v,ans);
        return ans;
    }
};

//--------------------------------------------------------------------------
/* 1. To create a subset, For a single element we have two possibilities either we select the element in the current subset or we do not.
2. So in the subset function we will iterate in the nums array and once we will select the element to be in the subset.
3. Then we will call the subset function for the next element.
4. After that we will pop the current element as we are not considering this element in this case.
5. All the subset formed will be pushed into the ans vector.
6. Finally, return the ans. */
