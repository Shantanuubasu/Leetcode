class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        ios_base::sync_with_stdio(false);

        int n=nums.size();

        if(n==1){
            return nums[0];
        }
        else if(nums[0]!=nums[1]){
            return nums[0];
        }
        else if(nums[n-1]!=nums[n-2]){
            return nums[n-1];
        }

        int low=0,high=n-1;

        while(low<=high){
            int mid=(low+high)/2;

            if(nums[mid]!=nums[mid-1] && nums[mid]!=nums[mid+1]){
                return nums[mid];
            }
            
            if((mid%2==0 && nums[mid]==nums[mid+1]) || (mid%2!=0 && nums[mid]==nums[mid-1])){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }

        return -1;
    }
};

//----------------------------------------------------------------------------------------------------------------
/* 1. We will use binary search, if n=1 then the only element is the answer.
2. If first element is not equal to second then first element is the answer.
3. If the last element is not equal to second last element then last element is the answer.
4. If none of the above condition satisfy then we will check if the element at mid does not have same element at its adjacent then it is the answer.
5. If the mid is even number then the next element should be the same number. If the mid is odd then the number before should be the same it means we are in left part of the array, we update low to mid+1.
6. else we update high to mid-1 to explore left part of the array. */
