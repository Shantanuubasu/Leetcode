class Solution {
public:
    int count=0;
    int maxi=0;
    void solve(vector<int> &nums, int currOr, int idx){
        for(int i=idx; i<nums.size(); i++){
            int prev=currOr;
            currOr|=nums[i];
            if(currOr==maxi){
                count++;
            }
            else if(currOr>maxi){
                maxi=currOr;
                count=1;
            }
            solve(nums, currOr, i+1);
            currOr=prev;
        }
    }

    int countMaxOrSubsets(vector<int>& nums) {
        ios_base::sync_with_stdio(false);

        int currOr=0;
        solve(nums, currOr, 0);

        return count;
    }
};

//----------------------------------------------------------------
/* 1. We will calculate the bitwise or of every subset.
2. We maintain global variables count and maxi, to keep track of maximum bitwise or and count of it.
3. Finally, return count. */
