//APPROACH-1-HASH_MAP

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        sort(nums.begin(),nums.end());
        int j=0;
        for(int i=0; i<nums.size(); ++i){
            if(nums[i]!=j){
                return j;
            }
            ++j;
        }
        return nums.size();
    }
};
//-----------------------------------------------------------------
/*In this problem, we have to find the missing number from the given array.
First we have sorted the array. Now we will iterate in the array and find the element which is not present.
If the number is not found then we will return that number.
Otherwise, we will return `nums.size()` because the only possibility now is that the last element is missing.*/

//APPROACH-2-SUM OF NATURAL NUMBERS

