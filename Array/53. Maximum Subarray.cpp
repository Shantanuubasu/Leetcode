class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        std::ios::sync_with_stdio(0);
        std::cin.tie(0);

        int n=nums.size();
        int sum=0,max=INT_MIN;

        for(int i=0; i<n; i++){
            sum+=nums[i];

            if(sum>max){
                max=sum;
            }
            if(sum<0){
                sum=0;
            }
            // if(max<0){
            //     max=0;
            // }
        }

        return max;
    }

};

//-------------------------------------------------
/* 1. We check if sum is greater than max then equate max to sum.
2. If sum is less than 0, make sum 0.
3. Finally return max. */
