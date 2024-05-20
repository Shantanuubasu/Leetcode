class Solution {
public:
    int solve(vector<int> &nums, int i, int Xor){
        if(i==nums.size()){
            return Xor;
        }

        int in=solve(nums,i+1,nums[i]^Xor);
        int ex=solve(nums,i+1,Xor);

        return in+ex;
    }

    int subsetXORSum(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        return solve(nums,0,0);
    }
};

//-----------------------------------------------------------
/* 1. To include every subset, we must first consider that the current element is the part of the subset.
2. Another case is that we do not consider the current element in our subset.
3. So when we include current element, so we xor it.
4. Otherwise we don't.
5. Finally we return the sum of both including and excluding xor. */
