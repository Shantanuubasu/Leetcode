class Solution {
public:
    void solve(vector<int>& candidates, int target, vector<int> v, vector<vector<int>> &ans, int j){
        if(target==0){
            ans.push_back(v);
            return;
        }

        for(int i=j; i<candidates.size(); i++){
            if(i>j && candidates[i]==candidates[i-1]){
                continue;
            }
            if(target<0){
                return;
            }
            v.push_back(candidates[i]);
            solve(candidates, target-candidates[i], v, ans, i+1);
            v.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        ios_base::sync_with_stdio(false);

        sort(candidates.begin(), candidates.end());

        vector<vector<int>> ans;
        vector<int> v;

        solve(candidates, target, v, ans, 0);

        return ans;
    }
};

//-------------------------------------------------------------------------------------------------
/* 1. We will first sort the candidates array.
2. In solve(), We will check every possibility, so we will run a loop from j to end of array to consider all the elements.
3. If the i>j and the ith element is same as last element then we will not take that element as we cannot take duplicates.
4. If at any stage target becomes less than 0 then we have to break as we cannot get any more valid subset further.
5. For each subset we will have two options, either to include the current element in the subset or to exclude it.
6. Initially we will include the element in the array and other till we will exclude it from the array.
7. Finally, when we have target as 0 then we will push the current subset in the ans array and return.
8. Finally, return ans. */
