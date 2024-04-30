class Solution {
public:

    string reverse(string str){
        int i=0,j=str.length()-1;

        while(i<j){
            char temp=str[i];
            str[i]=str[j];
            str[j]=temp;
            i++;
            j--;
        }

        return str;
    }
    bool isPalindrome(string s) {
        ios_base::sync_with_stdio(false);

        string str="";
        for(int i=0; i<s.length(); i++){
            if(s[i]>='A' && s[i]<='Z'){
                str+=char(s[i]+32);
            }
            else if(s[i]>='a' && s[i]<='z'){
                str+=s[i];
            }
            else if(s[i]>='0' && s[i]<='9'){
                str+=s[i];
            }
        }
        string revstr=reverse(str);
        //cout<<str<<endl<<revstr;
        if(str==revstr){
            return true;
        }

        return false;
    }
};

//-----------------------------------------------------------------------------------
/* 1. We wiil reconstruct the string with only lower case letters and numeric values.
2. Reverse the newly constructed string.
3. Compare, if both are same return true, else false. */
