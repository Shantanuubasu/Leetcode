class Solution {
public:
    void solve(vector<string> &ans, string &res, int n, int open, int close){
        ios_base::sync_with_stdio(false);

        if(res.length()==2*n){
            ans.push_back(res);
            return;
        }

        if(open<n){
            res.push_back('(');
            solve(ans, res, n, open+1, close);
            res.pop_back();
        }

        if(close<open){
            res.push_back(')');
            solve(ans, res, n, open, close+1);
            res.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        string res="";
        vector<string> ans;
        int open=0, close=0;
        solve(ans, res, n, open, close);
        return ans;
    }
};

//----------------------------------------------------------
/* 1. To create a valid parenthesis for n size, the actual number of open and close parenthesis will be 2*n.
2. We will create the possible parenthesis in string res and store it in ans.
3. We keep the track of open and close parenthesis so that only valid combination is formed.
4. In solve(), If the size of res formed is equal to 2*n then we push it in ans and return.
5. If open is less than n then we add ( to res and call solve() again with open+1. Then after return we pop_back from res.
6. If close is less than open then we add ) to res and call solve() again with close+1 and then after return we pop_back from res.
7. After we have explored all the combinations we return from the function and return ans. */
