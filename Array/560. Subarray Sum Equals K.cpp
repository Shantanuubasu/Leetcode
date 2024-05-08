class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false);

        unordered_map<int,int> mp;
        mp[0]=1;
        int sum=0,c=0;

        for(int i=0; i<nums.size(); i++){
            sum+=nums[i];
            int rem=sum-k;
            c+=mp[rem];
            mp[sum]++;
        }

        return c;
    }
};

//-------------------------------------------------------
/* 1. We will use prefix sum to solve this problem.
2. A map will store the prefix sums.
3. We will iterate in the array and find the remaining sum required to get k.
4. If we find the remaining sum then we add its count to our answer.
5. Finally return count. */
