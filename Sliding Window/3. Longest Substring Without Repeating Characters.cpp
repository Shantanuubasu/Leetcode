class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0, j=0;
        int maxLength=0;
        unordered_set<char> st;
        while(j<s.length()){
            while(st.find(s[j])!=st.end()){
                st.erase(s[i]);
                i++;
            }
            maxLength=max(maxLength, j-i+1);
            st.insert(s[j]);
            j++;
        }

        return maxLength;
    }
};

//------------------------------------------------------------
/* 1. Take two pointer i and j start both from 0.
2. Now check if the the element at j is present in the set or not. If yes, then erase the element at i from set and increment i.
3. Now update maxLength to max of maxLength or j-i+1.
4. Insert the element at j in set and increment j.
5. Finally, return maxLength. */
