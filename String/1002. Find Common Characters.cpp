class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        ios_base::sync_with_stdio(false);
        
        unordered_map<char,int> mp;
        
        for(char &ch: words[0]){
            mp[ch]++;
        }

        for(int i=1; i<words.size(); i++){
            unordered_map<char,int> temp;
            for(char &ch: words[i]){
                temp[ch]++;
            }
            for(auto &it: mp){
                if(temp.find(it.first)!=temp.end()){
                    mp[it.first]=min(temp[it.first],it.second);
                }
                else{
                    mp[it.first]=0;
                }
            }
        }

        vector<string> ans;

        for(auto &it: mp){
            
            for(int i=0; i<it.second; i++){
                string str="";
                str+=it.first;
                ans.push_back(str);
            }
        }

        return ans;
    }
};

//-------------------------------------------------------------------
/* 1. Take a map and store the frequencies of characters of the first word.
2. Now take an temp map for rest of the words and add frequencies of characters for each word.
3. Then compare the mp map to temp map if a character of mp is present in temp then update its frequency in the mp with the minimum frequency out of temp and mp.
4. Else, if it is not present in temp then update its count to 0.
5. Now take a ans vector of strings and store all the characters with frequency >0 in the ans.
6. Finally return ans. */
