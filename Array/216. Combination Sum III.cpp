class Solution {
public:
    void solve(int k, int n, vector<vector<int>> &ans, vector<int> v, int idx){
        if(n<0 || v.size()>k){
            return;
        }

        if(n==0 && v.size()==k){
            ans.push_back(v);
            return;
        }

        for(int i=idx; i<=9; i++){
            v.push_back(i);
            solve(k, n-i, ans, v, i+1);
            v.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        ios_base::sync_with_stdio(false);

        vector<vector<int>> ans;
        vector<int> v;

        solve(k, n, ans, v, 1);

        return ans;
    }
};

//-------------------------------------------------------------------
/* 1. In solve(), start from i as 1 to 9, for each i we have two options either to choose it in the subset or not.
2. If we include i in the subset then we check for another number and make n as n-i.
3. Otherwise, we pop the i from v.
4. If at any stage n is less tha 0 or v's size is greater than k then we return.
5. Also, if n is 0 and v's size is equal to k then we add the subset to ans and return.
6. Finally, return ans. */
