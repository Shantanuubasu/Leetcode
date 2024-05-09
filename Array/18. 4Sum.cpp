class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        ios_base::sync_with_stdio(false);

        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        long long int n=nums.size();

        for(int i=0; i<n; i++){
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }
            for(int j=i+1; j<n; j++){
                if(j>i+1 && nums[j]==nums[j-1]){
                    continue;
                }

                long long int k=j+1,l=n-1;

                while(k<l){
                    long long int sum=nums[i];
                    sum+=nums[j];
                    sum+=nums[k];
                    sum+=nums[l];
                    if(sum<target){
                        k++;
                    }
                    else if(sum>target){
                        l--;
                    }
                    else{
                        vector<int> temp={nums[i],nums[j],nums[k],nums[l]};
                        ans.push_back(temp);
                        k++;
                        l--;
                        while(k<l && nums[k]==nums[k-1]){
                            k++;
                        }
                        while(k<l && nums[l]==nums[l+1]){
                            l--;
                        }
                    }
                }
            }
        }

        return ans;

    }
};

//--------------------------------------------------------------------------------------------
/* 1. First we will sort the array.
2. We will use 4 pointers i,j,k and l.
3. i will start from index 0, j will start from i+1, k will start from j+1 and l from end of the array n-1.
4. We will add all the numbers at the 4 indexes and will check it.
5. If sum is less than target, it means we need a bigger sum so we will increment k.
6. If sum is less than target, it means we need a smaller sum so we decrement l.
7. When sum is equal to target then we will add the quadruplets to the answer array.
8. We will increment k and decrement l, sos that we don't consider the smae values again as we need unique quadruplets. */
