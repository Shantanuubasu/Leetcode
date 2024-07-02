class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        ios_base::sync_with_stdio(false);

        unordered_map<int,int> mp;
        for(int &i: nums1){
            mp[i]++;
        }

        vector<int> ans;
        for(int i=0; i<nums2.size(); i++){
            if(mp.find(nums2[i])!=mp.end()){
                ans.push_back(nums2[i]);
                mp[nums2[i]]--;
                if(mp[nums2[i]]==0){
                    mp.erase(nums2[i]);
                }
            }
        }

        return ans;
    }
};

//-----------------------------------------------------------
/* 1. Store the elements of one of the arrays in a map with their frequency.
2. Now iterate in the other array and if that number is in the map then push the number to ans array.
3. If at any point the frequency of any number becomes 0 then remove that element from the array.
4. Finally, return ans. */
