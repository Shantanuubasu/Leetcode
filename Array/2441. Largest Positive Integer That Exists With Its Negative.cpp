//APPROACH-1-HASH MAP

class Solution {
public:
    int findMaxK(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        unordered_map<int,int> mp;
        for(int i=0; i<nums.size(); i++){
            mp[nums[i]]++;
        }

        int mx=-1;
        for(int i=0; i<nums.size(); i++){
            if(mp[nums[i]*-1]>0 && nums[i]>mx){
                mx=nums[i];
            }
        }

        return mx;
    }
};

//----------------------------------------------------------------------------
/* 1. To solve this hash map will be used.
2. unordered_map `mp` will store the frequency of elements.
3. Then we check if the current elemnent's negation is present in the array or not.
4. If yes update `mx` if it is greater.
5. Finally return `mx`. */


//APPROACH-2-TWO POINTERS

class Solution {
public:
    int findMaxK(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        sort(nums.begin(),nums.end());

        int i=0,j=nums.size()-1;
        int ans=-1;
        while(i<j){
            if(-nums[i]==nums[j] && abs(nums[i])>ans){
                ans=abs(nums[j]);
            }
            else if(-nums[i]<nums[j]){
                j--;
            }
            else{
                i++;
            }
        }

        return ans;
    }
};

//----------------------------------------------------------------------
/* 1. Sort the array `nums`.
2. Take two pointers and start checking if numbers match the condition.
3. If yes, update the `ans` variable.
4. Return `ans`. */
