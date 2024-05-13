class Solution {
public:
    int minElements(vector<int>& nums, int limit, int goal) {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(0);

        long sum=accumulate(nums.begin(),nums.end(),0L);
        long diff=abs(goal-sum);
        return ceil((double)diff/limit);
    }
};

//-----------------------------------------------------------------
/* 1. Find the sum of array.
2. Calculate its absolute difference from the goal.
3. Then return the ceil of diff/limit. */
