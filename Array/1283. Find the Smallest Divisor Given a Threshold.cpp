class Solution {
public:
    int maxele(vector<int>& nums){
        int maxi=INT_MIN;
        for(int i=0; i<nums.size(); i++){
            maxi=max(maxi,nums[i]);
        }

        return maxi;
    }

    int calculatesum(vector<int> &nums, int mid){
        int sum=0;
        for(int i=0; i<nums.size(); i++){
            sum+=ceil((double)nums[i]/mid);
        }

        return sum;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        ios_base::sync_with_stdio(false);

        int low=1,high=maxele(nums);

        while(low<=high){
            int mid=(low+high)/2;

            int div=calculatesum(nums,mid);
            if(div<=threshold){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }

        return low;
    }
};

//--------------------------------------------------------------------------------
/* 1. We will use binary search, assign low as 1 and high as max element of the array.
2. Then we calculate the sum when all the elements are divided by mid.
3. If sum value is less than or equal to threshold then we update high as mid-1.
4. Else, we update low as mid+1.
5. Finally return low. */
