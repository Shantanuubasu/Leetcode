class Solution {
public:
    bool check(vector<int>& nums) {
        int c=0;
        for(int i=0; i<nums.size()-1; i++){
            if(nums[i]>nums[i+1]){
                c++;
            }

        }        
        if(nums[nums.size()-1]>nums[0]){
            c++;
        }
        
        if(c>1){
            return false;
        }

        return true;
    }
};

//-----------------------------------------------------------------------------
/* 1. Consider the array to be circular.
2. In this a previous number can be greater than successor only once.
3. If it is greater than more than once then its is not sorted and we will return false.
4. We will also check the same for last and first element because the array is circular. */
