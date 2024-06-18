class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        ios_base::sync_with_stdio(false);

        vector<pair<int,int>> v;
        for(int i=0; i<profit.size(); i++){
            v.push_back({difficulty[i],profit[i]});
        }

        sort(v.begin(),v.end());
        sort(worker.begin(),worker.end());

        int j=0;
        int maxProfit=0;
        long int ans=0;
        for(int i=0; i<worker.size(); i++){
            while(j<v.size() && v[j].first<=worker[i]){
                maxProfit = max(maxProfit, v[j].second);
                j++;
            }
            ans+=maxProfit;
        }

        return ans;
    }
};

//---------------------------------------------------------------------
/* 1. Make pair of difficulty and profit in an array.
2. Sort the new array and worker array.
3. Now find the for each worker the maximum profit they can earn.
4. Add the maxProfit to the ans.
5. Finally, return ans. */
