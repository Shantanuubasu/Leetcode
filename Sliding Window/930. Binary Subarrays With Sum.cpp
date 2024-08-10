class Solution {
public:
    int solve(vector<int> nums, int goal){
        if(goal<0){
            return 0;
        }

        int i=0, j=0;
        int c=0;
        int sum=0;
        while(j<nums.size()){
            sum+=nums[j];

            while(sum>goal){
                sum-=nums[i];
                i++;
            }

            c+=(j-i+1);
            j++;
        }

        return c;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return solve(nums, goal)-solve(nums,goal-1);
    }
};

//------------------------------------------------------------------------
/* 1. To find the number of subsets for goal, we can find the number of subset for less than or equal to goal minus less than goal.
2. In solve(), If goal is less than 0 then return 0.
3. Take two pointer i and j and start both from 0.
4. Add element at j to sum, if sum is greater than goal then subtract element at i from sum and increment i.
5. Add the number of subsets, i.e, j-i+1 to c and increment j.
6. Finally, return c. */
