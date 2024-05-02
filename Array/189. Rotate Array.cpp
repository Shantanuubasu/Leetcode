class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        int n=nums.size();
        k=k%n;      
        // while(k--){
        //     int last=nums[n-1];
        //     for(int j=n-2; j>=0; j--){
        //         nums[j+1]=nums[j];
        //     }
        //     nums[0]=last;
        // }

        reverse(nums.begin(),nums.end());
        reverse(nums.begin(),nums.begin()+k);
        reverse(nums.begin()+k,nums.end());
    }
};

//--------------------------------------------------------------------------
/* 1. First reverse the whole array.
2. Then reverse the first k elements.
3. Finally reverse the last k elements. */
