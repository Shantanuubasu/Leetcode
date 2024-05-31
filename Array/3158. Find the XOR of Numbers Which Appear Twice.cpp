class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        ios_base::sync_with_stdio(false);    
        
        unordered_map<int,int> mp;
        int ans=0;
        for(auto &i: nums){
            mp[i]++;
            if(mp[i]==2){
                ans^=i;
            }
        }
        return ans;


    }
};

//----------------------------------------------------------------------
/* 1. Keep a count of the numbers in a map.
2. When count becomes 2 for any element, do its xor.
3. Finally return ans. */
