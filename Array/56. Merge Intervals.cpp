class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        ios_base::sync_with_stdio(false);


        int n=intervals.size();
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        for(int i=0; i<n; i++){
            int start=intervals[i][0];
            int end=intervals[i][1];

            if(!ans.empty() && end<=ans.back()[1]){
                continue;
            }

            for(int j=i+1; j<n; j++){
                if(intervals[j][0]<=end){
                    end=max(end,intervals[j][1]);
                }
            }

            ans.push_back({start,end});
        }

        return ans;
    }
};

//-----------------------------------------------------------------------------
/* 1. We first sort the array.
2. Then we traverse in the array and find the its start and end.
3. If the ans array is not empty and end is less than the end in the answer array then it means it has already been covered.
4. Start a loop from i+1 and if the start of the new interval is less than end then update end to maximum of end or interval[j][1].
5. Then push back start and end. */
