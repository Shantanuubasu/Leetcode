class Solution {
public:
    bool isValid(string s) {
        stack<int> st;

        for(auto ch: s){
            if(ch=='('){
                st.push(')');
            }
            else if(ch=='['){
                st.push(']');
            }
            else if(ch=='{'){
                st.push('}');
            }
            else{
                if(st.empty()==false){
                    if(st.top()==ch){
                        st.pop();
                    }
                    else{
                        return false;
                    }
                }
                else{
                    return false;
                }
            }
        }

        if(st.empty()==false){
            return false;
        }

        return true;
    }
};

//--------------------------------------------------------------
/* 1. If we get (, [, { then we push its opposite bracket to the stack.
2. If we get a closing bracket then we check if stack is empty. if not then we check top element matches current element or not.
3. If yes then pop it, if not then return false.
4. After every element has been checked, check if stack is empty, if not then return false. Otherwise, we return true. */
