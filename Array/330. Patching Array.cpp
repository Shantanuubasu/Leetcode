class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        ios_base::sync_with_stdio(false);

        int i=0;
        long sum=0;
        int patch=0;

        while(sum<n){
            if(i<nums.size() && nums[i]<=sum+1){
                sum+=nums[i];
                i++;
            }
            else{
                patch++;
                sum+=sum+1;
            }
        }

        return patch;
    }
};

//--------------------------------------------------------------------
/* 1. We will run a loop till n, if current element of the array is less than or equal to sum+1 then we add it to sum as this number is reachable and increment i.
2. Else, we need to patch so we increment patch and add sum+1 to sum.
3. Finally, return patch. */
