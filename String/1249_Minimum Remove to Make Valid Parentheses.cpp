class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st;

        for(int i=0; i<s.length(); i++){
            if(s[i]=='('){
                st.push(i);
            }
            else if(s[i]==')'){
                if(!st.empty() && s[st.top()]=='('){
                    st.pop();
                }
                else{
                    st.push(i);
                }
            }
        }

        while(!st.empty()){
            s.erase(st.top(),1);
            st.pop();
        }

        return s; 
    }
};

//-------------------------------------------------------------------------
/* 1. We will use a stack, if we get `(` then we will push its index in the stack. If we get `)` then we will see if the element at top of the stack is `(` or not, if yes then we will pop it.
2. Else we will push index of `)`.
3. After this we will erase the remaining element in the stack from the string.
4. Finally, return `s`. */
