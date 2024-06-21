class Solution {
public:
    int strStr(string haystack, string needle) {
        int i=0,j=0;
        while(j<needle.size() && i<haystack.size()){
            if(haystack[i+j]==needle[j]){
                j++;
            }
            else{
                i++;
                j=0;
            }
        }

        if(i==haystack.size()){
            return -1;
        }

        return i;
    }
};

//-----------------------------------------------------------------------------
/* 1. We take two pointers, one for each string.
2. Now we match element of both the strings, if same then increment j.
3. Else, increment i and make j=0.
4. If i is equal to the size of haystack then it means we haven't found the match so we return -1.
5. Else we return i. */
