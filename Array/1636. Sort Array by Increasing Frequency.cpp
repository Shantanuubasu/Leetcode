class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        ios_base::sync_with_stdio(false);

        unordered_map<int, int> mp;
        for(int &i: nums){
            mp[i]++;
        }

        sort(nums.begin(), nums.end(), [&](int a, int b){
            if(mp[a]!=mp[b]){
                return mp[a]<mp[b];
            }
            else{
                return b<a;
            }
        });

        return nums;
    }
};

//-----------------------------------------------------------------------------
/* 1. We will map frequency to its elements in a map.
2. Then we will use sort function to sort the array with a condition if frequency of a and b are not equal then compare teir frequency.
3. If the frequency is same then compare its value.
4. The smaller number gets the priority here.
5. Finally, return nums. */
