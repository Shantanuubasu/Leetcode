class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        ios_base::sync_with_stdio(false);

        sort(strs.begin(),strs.end());
        string start=strs[0],end=strs[strs.size()-1];
        string ans="";
        for(int i=0; i<min(start.size(),end.size()); i++){
            if(start[i]!=end[i]){
                return ans;
            }
            ans+=start[i];
        }

        return ans;
    }
};

//---------------------------------------------------------------------------
/* 1. Sort the strs array.
2. Now take the starting element and last element of the array.
3. Now compare the characters of both start and end if same then add to ans.
4. If not, then return ans. */
