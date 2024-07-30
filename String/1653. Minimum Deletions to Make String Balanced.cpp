class Solution {
public:
    int minimumDeletions(string s) {
        ios_base::sync_with_stdio(false);

        stack<char> st;

        int ans=0;
        for(int i=0; i<s.length(); i++){
            if(s[i]=='a'){
                if(!st.empty() && st.top()=='b'){
                    st.pop();
                    ans++;
                }
                else{
                    st.push(s[i]);
                }
            }
            else{
                st.push(s[i]);
            }
        }

        return ans;
    }
};

//------------------------------------------------------------------
/* 1. We take a stack, if we get 'a' then we check if top of the stack is equal to 'b'. If yes, then pop it and increment ans.
2. Else, push into the stack.
3. Finally, return ans. */
