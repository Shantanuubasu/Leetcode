class Solution {
public:
    string makeGood(string s) {
        string ans="";

        for(char &ch : s) {
            if(ans.size() > 0 && (ch + 32 == ans.back() || ch - 32 == ans.back())) {
                ans.pop_back();
            } 
            else {
                ans.push_back(ch);
            }
        }
        return ans;
    }
};

//-------------------------------------------------------------------------------------------
//1. We will check if the character in `ans` is same as the next element in `s`, if yes then we remove it from `ans`.
//2. Else we will push it into `ans`.
//3. Finally, return `ans`.
