class Solution {
public:
    bool makeEqual(vector<string>& words) {
        ios_base::sync_with_stdio(false);

        unordered_map<char,int> mp;
        for(int i=0; i<words.size(); i++){
            for(int j=0; j<words[i].length(); j++){
                mp[words[i][j]]++;
            }
        }
        for(auto &it: mp){
            if(it.second%words.size()!=0){
                return false;
            }
        }

        return true;
    }
};

//-------------------------------------------------------------
/* 1. We will use a map to store the count of each character.
2. Then we will iterate in the map to find a character which is not a multiple of n (words' size).
3. If such a character is found then return false.
4. Otherwise return true. */
