class Solution {
public:
    string reverseWords(string s) {
        ios_base::sync_with_stdio(false);

        int n=s.length();
        string ans="";
        int i=0;
        string temp="";
        while(i<n){
            if(s[i]!=' '){
                temp+=s[i];
            }
            else if(s[i]==' '){
                if(ans!="" && temp!=""){
                    ans=temp+" "+ans;
                }
                else if(temp!=""){
                    ans+=temp;
                }
                temp="";
            }
            
            i++;
        }
        if(ans!="" && temp!=""){
            ans=temp+" "+ans;
        }
        else if(temp!=""){
            ans+=temp;
        }

        return ans;
    }
};

//-----------------------------------------------------------
/* 1. Iterate in the string, if we get a character other than blank space then add it to temp.
2. If we get a blank space then check if ans and temp are not empty, if satisfied then add temp+" "+ans to ans.
3. Else check if temp is not empty, if satisfied then add temp to ans.
4. Now make temp as "" and increment i.
5. Now for the last word we will again check if ans and temp are not empty then add temp+" "+ans to ans.
6. else check if temp is not empty and add temp to ans.
7. Finally, return ans. */
