class Solution {
public:
    bool isAnagram(string s, string t) {
        ios_base::sync_with_stdio(false);

        unordered_map<char,int> mp;
        for(char &i:s){
            mp[i]++;
        }
        for(char&j:t){
            if(mp[j]>0){
                mp[j]--;
            }
            else{
                return false;
            }
        }
        for(auto &it:mp){
            if(it.second>0){
                return false;
            }
        }

        return true;
    }
};

//-----------------------------------------------------------------
/* 1. We will map every character of s to its frequency.
2. Then we will check for string t, if the character is present in the map then decrease its count.
3. If not then return false.
4. Now we will check if every element of string s is used up or not.
5. If not then return false, else return true. */
