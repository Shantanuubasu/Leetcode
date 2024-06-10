class Solution {
public:
    int minAddToMakeValid(string s) {
        ios_base::sync_with_stdio(false);

        int open=0,close=0;
        for(int i=0; i<s.length(); i++){
            if(s[i]=='('){
                open++;
            }
            else{
                if(open>0){
                    open--;
                }
                else{
                    close++;
                }
            }
        }

        return open+close;
    }
};

//-----------------------------------------------
/* 1. If we get a ( then we will increment open.
2. If we get ) and open>0 then we will decrement open
3. else we will increment close.
4. Finally return open+close. */
