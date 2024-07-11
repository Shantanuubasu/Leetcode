class Solution {
public:
    string reverseParentheses(string s) {
        ios_base::sync_with_stdio(false);

        stack<int> st;
        string res="";

        for(char &i:s){
            if(i=='('){
                st.push(res.length());
            }
            else if(i==')'){
                int top=st.top();
                st.pop();
                reverse(res.begin()+top, res.end());
            }
            else{
                res+=i;
            }
        }

        return res;
    }
};

//--------------------------------------------------------------------------------
/* 1. We will use a stack to store the length of res at that point.
2. we take an empty string res to store the result.
3. We iterate in string s, if we get ( then we push the length of the res, which is the number of characters already added to res.
4. If we get ) then we take the top of the stack out and reverse the from the top to end of the string res.
5. Else, we add the character to res.
6. Finally, return res. */
