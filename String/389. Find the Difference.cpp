class Solution {
public:
    char findTheDifference(string s, string t) {
        ios_base::sync_with_stdio(false);

        unordered_map<char,int> mp;
        for(char &i:s){
            mp[i]++;
        }
        for(char &i:t){
            mp[i]--;
            if(mp[i]<0){
                return i;
            }
        }
        return '\0';
    }
};

//--------------------------------------------------------
/* 1. We will store the count of each element of s in map.
2. Then we keep on decrementing the count for elements of t.
3. For the extra letter added, the count will become negative then we will return that character. */
