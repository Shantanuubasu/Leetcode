class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false);

        unordered_map<int,int> mp;
        mp[0]=-1;
        int sum=0;
        for(int i=0; i<nums.size(); i++){
            sum+=nums[i];
            int mod=sum%k;
            if(mp.find(mod)!=mp.end() && i-mp[mod]>=2){
                return true;
            }
            else if(mp.find(mod)==mp.end()){
                mp[mod]=i;

            }
        }

        return false;
    }
};

//------------------------------------------------------------------------
/* 1. We will store the mod of each sum in the map.
2. If we find a repetitive mod, it means that the number added to sum is a multiple of k then we will check if its length is greater than or equal to 2 or not.
3. If yes then return true.
4. Else we check if mod is present in the map or not if not then add it to the map.
5. If no multiple of k is found then return false. */
