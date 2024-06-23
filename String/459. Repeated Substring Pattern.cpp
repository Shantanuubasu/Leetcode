class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        ios_base::sync_with_stdio(false);

        int n=s.length();
        for(int i=n/2; i>=1; i--){
            if(n%i==0){
                int t=n/i;
                string str=s.substr(0,i);
                string newStr="";
                while(t--){
                    newStr+=str;
                }

                if(newStr==s){
                    return true;
                }
            }
        }

        return false;
    }
};

//-------------------------------------------------------
/* 1. We can have a pattern at most to n/2 length in a string.
2. So we run a for loop for n/2 and we can only form pattern if i divides n.
3. Now we take the number of times a pattern can repeat in t.
4. we store the pattern in str and add the pattern t times in newStr.
5. If newStr and s matches then we return true.
6. Otherwise, we return false. */
