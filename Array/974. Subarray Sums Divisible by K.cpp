class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false);

        unordered_map<int,int> mp;
        int sum=0;
        int c=0;
        mp[0]=1;
        for(int i=0; i<nums.size(); i++){
            sum+=nums[i];
            int rem=sum%k;
            if(rem<0){
                rem+=k;
            }
            if(mp.find(rem)!=mp.end()){
                c+=mp[rem];
            }
            mp[rem]++;
        }

        return c;
    }
};

//---------------------------------------------------------------
/* 1. Take a map to store the prefixsum%k values.
2. Now check if mod value is less than 0 if yes then adjust it by adding k to it.
3. Now find if the mod value is present in the map or not.
4. If yes then add its frequency to c.
5. If not then add it to the map.
6. Finally return c. */
