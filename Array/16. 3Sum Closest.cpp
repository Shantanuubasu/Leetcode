class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        ios_base::sync_with_stdio(false);

        sort(nums.begin(),nums.end());
        int diff=INT_MAX,ans=0;

        for(int i=0; i<nums.size(); i++){
            int j=i+1;
            int k=nums.size()-1;
            while(j<k){
                int sum=nums[i]+nums[j]+nums[k];
                if(abs(sum-target)<diff){
                    ans=sum;
                    diff=abs(sum-target);
                }
                if(sum<=target){
                    j++;
                }
                else{
                    k--;
                }
            }
        }

        return ans;
    }
};

//--------------------------------------------------------------------
/* 1. We will use 3 pointer approach, i, j and k. i will start from index 0, j will start from index i+1 and k will start from index n-1 and will move backwards.
2. First we will sort the array.
3. For every triplet, we will check its difference from the target.
4. If it is less than the current diff then update diff and answer.
5. If sum is less than target then increment j, otherwise decrement k. */
