class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        ios_base::sync_with_stdio(false);

        stack<int> st;
        for(int i=0; i<tokens.size(); i++){
            if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/"){
                int a=st.top();
                st.pop();
                int b=st.top();
                st.pop();
                int num=0;
                if(tokens[i]=="+"){
                    num=a+b;
                }
                else if(tokens[i]=="-"){
                    num=b-a;
                }
                else if(tokens[i]=="*"){
                    num=a*b;
                }
                else if(tokens[i]=="/"){
                    num=b/a;
                }
                st.push(num);
            }    
            else{
                st.push(stoi(tokens[i]));
            }
        }
        return st.top();
    }
};

//---------------------------------------------------------------------
/* 1. We will use a stack to solve the problem.
2. Iterate in the tokens array and if the character is a number then push it into the stack.
3. If the character is an operator then perform the operation by popping two numbers from top of the stack and push the result into the stack.
4. Finally the answer will be found at the top of the stack. */
