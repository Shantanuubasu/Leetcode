class Solution {
public:
    bool ispalin(string &s, int i, int j){
        while(i<j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }

        return true;
    }

    void sub(string& s, int idx, vector<string> curr, vector<vector<string>> &res){
        if(idx==s.length()){
            res.push_back(curr);
            return;
        }
        for(int i=idx; i<s.length(); i++){
            if(ispalin(s,idx,i)){
                curr.push_back(s.substr(idx,i-idx+1));
                sub(s,i+1,curr,res);
                curr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        ios_base::sync_with_stdio(false);

        vector<string> curr;
        vector<vector<string>> res;

        sub(s,0,curr,res);

        return res;
    }
};

//------------------------------------------------------------------------
/* 1. We iterate in the string for every element we get two option to create a partition or not.
2. If the substring is a palindrome then we create a partition and add the current substring to curr.
3. In Other condition we do not consider the current substring so we pop back.
4. Finally when we reach end of the string then we can say that we have created maximum possible partitions for the current subset.
5. So we push curr to res.
6. Finally return res. */
