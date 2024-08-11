class Solution {
public:
    int numberOfSubstrings(string s) {
        int ans=0;
        vector<int> v(3, -1);
        for(int i=0; i<s.length(); i++){
            v[s[i]-'a']=i;
            if(v[0]!=-1 && v[1]!=-1 && v[2]!=-1){
                ans+=(1 + min({v[0],v[1],v[2]}));
            }
        }

        return ans;
    }
};

//-------------------------------------------------------------
/* 1. Take an array to store the indexof last occurance of a b or c.
2. If the value in the array at idex 0 1 and 2 is not -1 then add 1 + minimum of the value of 3 indexes ans.
3. Finally, return ans. */
