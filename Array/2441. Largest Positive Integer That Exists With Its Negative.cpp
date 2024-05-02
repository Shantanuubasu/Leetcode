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
