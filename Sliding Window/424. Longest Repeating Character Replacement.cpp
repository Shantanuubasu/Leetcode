class Solution {
public:
    int characterReplacement(string s, int k) {
        int i=0, j=0;
        int maxFreq=0, ans=0;
        unordered_map<char, int> mp(26);

        while(j<s.length()){
            mp[s[j]]++;
            maxFreq=max(maxFreq, mp[s[j]]);

            if((j-i+1)-maxFreq>k){
                mp[s[i]]--;
                i++;
            }

            ans=max(ans, (j-i+1));
            j++;
        }

        return ans;
    }
};

//--------------------------------------------------------------
/* 1. Take two pointers i and j and start both from 0th index.
2. Now add the element at j to map and update maxfreq to max of maxFreq or the frequency of element at j.
3. Now check the number of conversions need and if it is greater than k then decrement the count of element at i in map and increment i.
4. Update ans to max of ans or j-i+1 and increment j.
5. Finally, return ans. */
