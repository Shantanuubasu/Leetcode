class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        ios_base::sync_with_stdio(false);
        
        int low=0,high=numbers.size()-1;

        while(low<high){
            int sum=numbers[low]+numbers[high];
            if(sum==target){
                return {low+1,high+1};
            }
            else if(sum<target){
                low++;
            }
            else{
                high--;
            }
        }

        return {-1,-1};
    }
};

//-------------------------------------------------------------------------
/* 1. Take two pointers, start one from front of the array, other from back.
2. If the at both the pointers is equal to target then return pointer position.
3. If sum is less than target then we need greater sum so we increment low.
4. If sum is greater than target then we need smaller sum so we decrement high. */
