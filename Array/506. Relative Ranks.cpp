class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        ios_base::sync_with_stdio(false);

        vector<int> sorted=score;
        sort(sorted.begin(),sorted.end(), greater<int>());
        unordered_map<int,string> mp;
        for(int i=0; i<sorted.size(); i++){
            if(i==0){
                mp[sorted[i]]="Gold Medal";
            }
            else if(i==1){
                mp[sorted[i]]="Silver Medal";
            }
            else if(i==2){
                mp[sorted[i]]="Bronze Medal";
            }
            else{
                mp[sorted[i]]=to_string(i+1);
            }
        }

        vector<string> ans;
        for(int i:score){
            ans.push_back(mp[i]);
        }

        return ans;
    }
};

//---------------------------------------------------------
/* 1. First we will sort the array in decreasing order and then map it accordingly to its rank.
2. Then we will use the original array to push the ranks according to its original sequence. */
