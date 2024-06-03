class Solution {
public:
    int appendCharacters(string s, string t) {
        ios_base::sync_with_stdio(false);

        int i=0,j=0;
        while(i<s.size() && j<t.size()){
            if(s[i]==t[j]){
                i++;
                j++;
            }
            else{
                i++;
            }
        }

        return t.size()-j;
    }
};

//-------------------------------------------------------------------
/* 1. Take two pointers i and j.
2. If both the characters in s and t match then increment i and j.
3. Otherwise, increment only i.
4. Finally return t.size()-j. */
