class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

        int total=0;

        for(int &x:nums){
            total^=x;
        }

        int a=total^k;

        return __builtin_popcount(a);
    }
};

//------------------------------------------------------------------------------------------------
/* 1. We will take the `xor` of each element of the `nums` array.
2. we find the `xor` of `total` and `k`.
3. Finally, we return the count of `1` in `a` using `__builtin_popcount()`. */
