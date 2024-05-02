class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0;
        
        for(int j=1; j<nums.size(); j++){
            if(nums[j]!=nums[j-1]){
                nums[++i]=nums[j];
            }
        }

        return i+1;
    }
};

//----------------------------------------------------------
/* 1. Traverse in the array and replace all duplicates with unique elements.
2. Return the length of part of unique elements only. */
