class Solution {
public:

    void sub(int idx,vector<int>& nums, int k, int &res, unordered_map<int,int>& mp){
        
        if(idx>=nums.size()){
            res++;
            return;
        }

        sub(idx+1,nums,k,res,mp);

        if(!mp[nums[idx]-k] && !mp[nums[idx]+k]){
            mp[nums[idx]]++;
            sub(idx+1,nums,k,res,mp);
            mp[nums[idx]]--;
        }

    }

    int beautifulSubsets(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false);

        int res=0;
        unordered_map<int,int> mp;

        sub(0,nums,k,res,mp);

        return res-1;
    }
};

//--------------------------------------------------------------------------
/* 1. We will use a map to keep count of the elements in the subset.
2. For every element we have two options either to take it in the subset or exclude it.
3. If we do not take it into the subset then we can simply move forward by making idx+1.
4. If we decide to take it in the subset then we will check if that element should not make the difference of the subset as k.
5. This can be checked from the map by finding nums[idx]-k and nums[idx]+k element.
6. If both not found then we add the current element to the map.
7. We then move onto next element and after return we make the decrement the count of that element in the map.
8. When we have reached successfully to the end of the array that means we have got a valid subset and increment result and return.
9. Finally return res. */
