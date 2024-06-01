class Solution {
public:
    int countSub(vector<int> &nums, int k, int mid){
        int subsum=0;
        int sub=1;
        for(int i=0; i<nums.size(); i++){
            if(subsum+nums[i]<=mid){
                subsum+=nums[i];
            }
            else{
                sub++;
                subsum=nums[i];
            }
        }

        if(sub>k){
            return true;
        }
        return false;
    }

    int splitArray(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false);

        if(k>nums.size()){
            return -1;
        }
        int maxi=INT_MIN,sum=0;
        for(int i=0; i<nums.size(); i++){
            maxi=max(maxi,nums[i]);
            sum+=nums[i];
        }

        int low=maxi,high=sum;

        while(low<=high){
            int mid=low+(high-low)/2;

            if(countSub(nums,k,mid)){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }

        return low;
    }
};

//---------------------------------------------------------------
/* 1. We will apply binary search, assign low and high as max element of the array and sum of all elements of the array respectively.
2. Calculate mid and use countSub to calculate the number of subarrays that can be created with maximum sum of mid.
3. If number of subarrays is greater than k then return true, else false.
4. If true update low as mid+1, so that we search for a higher mid value to create less subarrays.
5. Else update high to mid-1.
6. Finally return low. */
