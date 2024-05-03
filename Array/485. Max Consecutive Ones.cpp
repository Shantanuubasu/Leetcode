class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int c=0,ans=-1;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==0){
                c=0;
            }
            if(nums[i]==1){
                c++;
            }
            ans=max(ans,c);
        }

        return ans;
    }
};

//-------------------------------------------------------------------
/* 1. We will keep incrementing value of count by 1, if we get a 1 in the array.
2. We will make count 0 when we get 0 in array.
3. We keep on updating ans for max value.
4. Return ans. */
