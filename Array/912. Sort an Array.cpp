class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        ios_base::sync_with_stdio(false);

        unordered_map<int, int> mp;
        for(int &i: nums){
            mp[i]++;
        }

        int mini=*min_element(nums.begin(), nums.end());
        int maxi=*max_element(nums.begin(), nums.end());

        int idx=0;
        for(int i=mini; i<=maxi; ++i){
            while(mp[i]>0){
                nums[idx]=i;
                mp[i]--;
                idx++;
            }
        }

        return nums;
    }
};

//---------------------------------------------------------------------------
/* 1. We will create a hash table to make the numbers to its frequency.
2. Now find the minimum and maximum element of the array.
3. Now add number to the array according to the frequency within the range of min and max element.
4. Return nums. */
