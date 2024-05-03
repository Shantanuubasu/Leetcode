class Solution {
public:
    int singleNumber(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);

        int ans=nums[0];
        for(int i=1; i<nums.size(); i++){
            ans^=nums[i];
        }

        return ans;
    }
};

//-------------------------------------------------------------
/* 1. Xor of a number with itself is 0 and with 0 is the number itself.
2. So we xor every number in array, the result will be the number that is present only once in the array as other elements' xor is 0. */
