class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        ios_base::sync_with_stdio(false);

        int n=nums.size();
        int ans=0;
        sort(nums.begin(),nums.end());
        for(int i=1; i<n; i++){
            if(nums[i]<=nums[i-1]){
                ans+=(nums[i-1]+1)-nums[i];
                nums[i]=nums[i-1]+1;
            }
        }

        return ans;
    }
};

//----------------------------------------------------------------
/* 1. First we will sort the array.
2. Now we will check if the current element in the array is less than equal to previous element or not.
3. If yes then it means the number has already occured in the array once so we update it to previous element + 1 and then add the difference between the current element at the position and element it was already there.
4. Finally return ans. */
