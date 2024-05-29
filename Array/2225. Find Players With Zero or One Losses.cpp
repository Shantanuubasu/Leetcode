class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        ios_base::sync_with_stdio(false);

        unordered_map<int,int> mp;
        for(auto &it: matches){
            mp[it[0]]+=0;
            mp[it[1]]++;
        }

        vector<vector<int>> ans(2);

        for(auto &it: mp){
            if(it.second<1){
                ans[0].push_back(it.first);
            }
            else if(it.second==1){
                ans[1].push_back(it.first);
            }
        }
        sort(ans[0].begin(),ans[0].end());
        sort(ans[1].begin(),ans[1].end());
        return ans;
    }
};

//-----------------------------------------------------------------
/* 1. Take a unordered_map and store the count of matches lost by every player.
2. Now in the ans vector, if the count of lost matches is 0 then push the element in the ans[0].
3. If the count of lost matches is 1 then push the element in the ans[1].
4. Then sort both the sub vectors.
5. Finally return ans. */
