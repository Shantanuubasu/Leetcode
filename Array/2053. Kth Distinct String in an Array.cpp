class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> mp;

        for(string str: arr){
            mp[str]++;
        }

        for(int i=0; i<arr.size(); i++){
            if(mp[arr[i]]==1){
                k--;
                mp[arr[i]]--;
            }
            if(k==0){
                return arr[i];
            }
        }

        return "";
    }
};

//------------------------------------------------------------
/* 1. Map all the strings to their frequencies.
2. Then check if an element has count as 1 then decrement k.
3. If k becomes 0 at some point return the current string. */
