class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        ios_base::sync_with_stdio(false);

        unordered_map<int, string> mp;

        for(int i=0; i<names.size(); i++){
            mp[heights[i]]=names[i];
        }

        sort(heights.rbegin(), heights.rend());

        vector<string> res;
        for(int i=0; i<heights.size(); i++){
            res.push_back(mp[heights[i]]);
        }

        return res;
    }
};

//------------------------------------------------------------------------------------------------
/* 1. We will use a map to map height to names.
2. Then we will sort the heights in decreasing order.
3. Then we will push the name of the people with highest to lowest from the map to res.
4. Finally, return res. */
