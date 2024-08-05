class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> v;
        for(int i=0; i<n; i++){
            int preSum=0;
            for(int j=i; j<n; j++){
                preSum+=nums[j];
                v.push_back(preSum);
            }
        }

        sort(v.begin(), v.end());
        int sum=0, mod=1e9+7;
        for(int i=left-1; i<right; i++){
            sum=(sum+v[i])%mod;
        }

        return sum;
    }
};

//--------------------------------------------------------------------------------------
/* 1. First we will find the prefix sum of all the continuous subsets and store it into v.
2. Now we will sort v.
3. Start iterating from left-1 to right and add current element to sum and also do the mod using 1e9+7.
4. Finally, return sum. */
