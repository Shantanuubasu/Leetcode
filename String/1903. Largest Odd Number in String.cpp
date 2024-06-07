class Solution {
public:
    string largestOddNumber(string num) {
        ios_base::sync_with_stdio(false);

        int n=num.size();
        int i=n-1;
        while(i>=0){
            if((num[i]-'0')%2!=0){
                return num.substr(0,i+1);
            }
            i--;
        }

        return "";
    }
};

//------------------------------------------------------
/* 1. Traverse the string from the back, if we get any odd number then return the substring starting from 0 to i+1.
2. Else return "". */
