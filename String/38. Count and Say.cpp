class Solution {
public:
    string countAndSay(int n) {
        ios_base::sync_with_stdio(false);

        if(n==1){
            return "1";
        }

        string str=countAndSay(n-1);

        string res="";
        for(int i=0; i<str.length(); i++){
            char ch=str[i];
            int count=1;

            while(i<str.length()-1 && str[i]==str[i+1]){
                count++;
                i++;
            }

            res+=to_string(count)+string(1,ch);
        }

        return res;
    }
};

//-----------------------------------------------------------------
/* 1. If n=1 then return 1.
2. Now call the function for n-1.
3. Count the number of occurances of a every element and add it with its count to the string.
4. Finally return string. */
