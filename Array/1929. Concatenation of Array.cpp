class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        ios_base::sync_with_stdio(false);

        vector<int> ans=nums;
         for(int i=0; i<nums.size(); i++){
            ans.push_back(nums[i]);
        }
        return ans;
    }
};

//------------------------------------------------------------------
/* 1. Take a new array ans and initialize it with nums.
2. Now push the elements of nums in the ans array.
3. Finally, return ans. */
