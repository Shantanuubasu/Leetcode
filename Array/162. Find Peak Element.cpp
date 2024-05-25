class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        ios_base::sync_with_stdio(false);

        int n=nums.size();

        if(n==1){
            return 0;
        }
        else if(nums[0]>nums[1]){
            return 0;
        }
        else if(nums[n-1]>nums[n-2]){
            return n-1;
        }

        int low=1,high=n-2;

        while(low<=high){
            int mid=(low+high)/2;

            if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1]){
                return mid;
            }
            else if(nums[mid]>nums[mid-1]){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }

        return -1;
    }
};

//----------------------------------------------------------------------------------
/* 1. If the array contains only one element then we return 0.
2. If the first element is greater than second then we return 0.
3. If last element is greater than second last element we return n-1.
4. If none of the above condition satisfies then we apply binary search, if mid is greater than its adjacent elements then we return mid.
5. If the mid is greater than its previous element that means peak is on the right, so we update low to mid+1.
6. else we update high to mid-1. */
