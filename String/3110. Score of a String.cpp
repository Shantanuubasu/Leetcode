class Solution {
public:
    int scoreOfString(string s) {
        int ans=0;
        for(int i=1; i<s.size(); i++){
            ans+=(int)abs(s[i]-s[i-1]);
        }

        return ans;
    }
};

//-----------------------------------------------------
/* 1. Iterate in the string starting from index 1.
2. Add the absolute difference of current and previous character to the ans.
3. Finally return ans. */
