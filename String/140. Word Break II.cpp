class Solution {
public:
    void solve(int i, string currsentence, vector<string>& res, string s,unordered_set<string>& st){
        if(i>=s.length()){
            res.push_back(currsentence);
            return;
        }

        for(int j=i; j<s.length(); j++){
            string temp=s.substr(i,j-i+1);
            if(st.count(temp)){
                string tempsentence=currsentence;
                if(!currsentence.empty()){
                    currsentence+=" ";
                }
                currsentence+=temp;
                solve(j+1,currsentence,res,s,st);
                currsentence=tempsentence;
            }

        }

    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        ios_base::sync_with_stdio(false);

        unordered_set<string> st;
        vector<string> res;
        for(string &s:wordDict){
            st.insert(s);
        }   

        string currsentence="";
        solve(0,currsentence, res, s,st);
        return res;
    }
};

//-------------------------------------------------------------------------------
/* 1. We will go at every element and check if the current subset is part of the wordDict or not.
2. If yes then we consider that word and add it to currsentence and move forward.
3. Otherwise, we don't take the current word and move forward anyways. */
