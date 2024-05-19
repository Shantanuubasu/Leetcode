class Solution {
public:
    int maxProduct(vector<int>& nums) {
        ios_base::sync_with_stdio(false);

        int pre=1,suf=1;
        int maxi=INT_MIN;
        int n=nums.size();
        for(int i=0; i<n; i++){
            if(pre==0){
                pre=1;
            }
            if(suf==0){
                suf=1;
            }

            pre*=nums[i];
            suf*=nums[n-i-1];
            maxi=max(maxi,max(pre,suf));
        }

        return maxi;

        
    }
};

//-----------------------------------------------------------
/* 1. We will use prefix and suffix product for each element.
2. If at any time pre and suf becomes zero, we will reset the product to 1.
3. We will store the maximum of maxi and max of pre or suf as our answer.
4. Finally return maxi. */
