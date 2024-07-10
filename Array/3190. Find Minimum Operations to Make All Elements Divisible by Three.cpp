class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        ios_base::sync_with_stdio(false);

        int op=0;
        for(int &i:nums){
            op+=min(i%3, 3-(i%3));
        }

        return op;
    }
};

//------------------------------------------------------------
/* 1. The number of operations for each number would be minimum of nums[i]%3 and 3-(nums[i]%3).
2. Finally, return op. */
