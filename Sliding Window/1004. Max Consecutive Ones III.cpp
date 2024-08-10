class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i=0, j=0;
        int zero=0;
        int ans=0;
        while(j<nums.size()){
            if(nums[j]==0){
                zero++;
            }
            while(zero>k){
                if(nums[i]==0){
                    zero--;
                }
                i++;
            }

            ans=max(ans, j-i+1);
            
            j++;
        }
        return ans;
    }
};

//-----------------------------------------------------------------
/* 1. Take two pointer starting both from 0th index.
2. If the element at j is 0 then increment zero.
3. If zero is greater than k then check if the element at i is 0, if yes then decrement zero and increment i.
4. Update ans to maximum of ans or j-i+1 and increment j.
5. Finally, return ans. */
