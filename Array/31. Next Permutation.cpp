class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        int n=nums.size();
        int ind=-1;

        for(int i=n-2; i>=0; i--){
            if(nums[i]<nums[i+1]){
                ind=i;
                break;
            }
        }

        if(ind==-1){
            reverse(nums.begin(),nums.end());
            return;
        }

        for(int i=n-1; i>=ind; i--){
            if(nums[i]>nums[ind]){
                swap(nums[i],nums[ind]);
                break;
            }
        }

        reverse(nums.begin()+ind+1, nums.end());
    }
};

//----------------------------------------------------------------
/* 1. Find the break point where the condition `nums[i]<nums[i+1]` from back of the array satisfies.
2. If no break point is found, means thge array is in decreasing order and the next permutation would be its asecending order, so reverse and return.
3. If break point found, swap it with the element greater than that from the back of the array.
4. Reverse the part after the break point. */
