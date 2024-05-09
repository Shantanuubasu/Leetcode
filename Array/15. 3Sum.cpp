class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
    
        int n=nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for(int i=0; i<n; i++){
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }
            int j=i+1,k=n-1;
            while(j<k){

                int sum=nums[i]+nums[j]+nums[k];

                if(sum<0){
                    j++;
                }
                else if(sum>0){
                    k--;
                }
                else{
                    vector<int> temp={nums[i],nums[j],nums[k]};
                    ans.push_back(temp);
                    j++;
                    k--;
                    while(j<k && nums[j]==nums[j-1]){
                        j++;
                    }
                    while(j<k && nums[k]==nums[k+1]){
                        k--;
                    }
                }
            }
        }

        return ans;
    }
};

//---------------------------------------------------------------------------
/* 1. First we will sort the array.
2. Then we will take three pointers i,j and k.
3. i will start from index 0, j will from i+1 and k from n-1, i.e, end of the array.
4. We will then check if the sum at 3 pointers is if less than 0 then we will increment j as we need to increase the sum.
5. If sum is grater than 0 then we need to decrease the sum then we will decrement k.
6. When sum equal to 0 then we will push the triplet into the ans array and increment j and decrement k till the value of both change as we need unique triplets. */
