class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        ios_base::sync_with_stdio(false);

        int n=pref.size();
        vector<int> ans(n);
        int Xor=pref[0];
        ans[0]=pref[0];
        for(int i=1; i<n; i++){
            ans[i]=Xor^pref[i];
            Xor^=ans[i];
        }
        return ans;
    }
};

//-----------------------------------------------------------------
/* 1. To find the xor we will keep track of current xor and find the xor of current element with current xor.
2. Finally return ans. */
