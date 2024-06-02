class Solution {
public:
    void reverseString(vector<char>& s) {
        ios_base::sync_with_stdio(false);
        
        int i=0,j=s.size()-1;

        while(i<j){
            char temp=s[i];
            s[i]=s[j];
            s[j]=temp;
            i++;
            j--;
        }

    }
};

//------------------------------------------------------
/* 1. Take two pointers, initialize first with 0 and other with size of string -1.
2. Keep interchanging the characters at both the pointers and increment first pointer and decrement second pointer. */
