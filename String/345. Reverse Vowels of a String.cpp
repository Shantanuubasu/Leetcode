class Solution {
public:
    bool isvowel(char s){
        s=tolower(s);
        if(s=='a' || s=='e' || s=='i' || s=='o' || s=='u'){
            return true;
        }

        return false;
    }
    string reverseVowels(string s) {
        ios_base::sync_with_stdio(false);

        int n=s.length();
        int i=0,j=n-1;
        while(i<j){
            while(isvowel(s[i])==false && i<j){
                i++;
            }
            while(isvowel(s[j])==false && i<j){
                j--;
            }

            char temp=s[i];
            s[i]=s[j];
            s[j]=temp;
            i++;
            j--;
        }

        return s;
    }
};

//----------------------------------------------------------------
/* 1. Take 2 pointers i and j, point i to index 0 and j to n-1.
2. Find the first vowel from either sides.
3. Then swap the two places.
4. Repeat the steps for i<j.
5. Finally return s. */
