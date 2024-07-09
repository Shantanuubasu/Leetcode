class Solution {
public:
    void solve(int n, int k, vector<vector<int>> &ans, vector<int> v, int idx){
        ios_base::sync_with_stdio(false);

        if(v.size()==k){
            ans.push_back(v);
            return;
        }

        for(int i=idx; i<=n; i++){
            v.push_back(i);
            solve(n, k, ans, v, i+1);
            v.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> v;

        solve(n, k, ans ,v, 1);

        return ans;
    }
};

//----------------------------------------------------------------
/* 1. We will try to generate all the subsets from [1, n].
2. Wheneever a subset reaches the size of k then we add it to ans and return.
3. Finally, we return ans. */
