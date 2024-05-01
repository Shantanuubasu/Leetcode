class Solution {
public:

    int binarySearch(int target_ind,int k, vector<int>& nums, vector<long>& prefix){
        long l=0,r=target_ind,best_ind=target_ind;

        while(l<=r){
            long mid=l+(r-l)/2;

            long cnt=target_ind-mid+1;
            long nxt=nums[target_ind]*cnt;

            long prev=prefix[target_ind]-prefix[mid]+nums[mid];

            long ops=nxt-prev;

            if(ops>k){
                l=mid+1;
            }
            else{
                r=mid-1;
                best_ind=mid;
            }
        }

        return target_ind-best_ind+1;
    }

    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<long> prefix(n);

        prefix[0]=nums[0];
        for(int i=1; i<n; i++){
            prefix[i]=prefix[i-1]+nums[i];
        }
        int res=0;
        for(int i=0; i<n; i++){
            res=max(res,binarySearch(i,k,nums,prefix));
        }

        return res;
    }
};

//-------------------------------------------------------------------
/* 1. The approach we are going to use is binary search.
2. We set a target variable and set all the elements between the `mid` and `r` to that target variable and find the sum of it.
3. If the difference of sum after operation and before operation is greater than `k`, then we update `l` to `mid+1`.
4. Otherwise, we update `r` to `mid-1` and store index of `mid` in `best_ind`.
5. We do this for every element is the array `nums`.
6. Finally, get the maximum value and return `res`. */
