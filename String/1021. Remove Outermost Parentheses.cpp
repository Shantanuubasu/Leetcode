class Solution {
public:
    string removeOuterParentheses(string s) {
        ios_base::sync_with_stdio(false);

        string ans="";
        int count=0;

        for(int i=0; i<s.length(); i++){
            if(s[i]=='('){
                if(count>0){
                    ans+=s[i];
                }
                ++count;
            }
            else{
                --count;
                if(count>0){
                    ans+=s[i];
                }
            }
        }

        return ans;
    }
};

//---------------------------------------------------------
/* 1. Whenever we get a ( then we check if count>0 if yes then add ( to the ans and increment count.
2. When we get ) we first decrement count and then check if count>0, if yes then add ) to the ans.
3. Finally return ans. */
