class Solution {
public:
    int mapNum(int nums, vector<int> &mapping){
        if(nums<10){
            return mapping[nums];
        }

        int newNum=0;
        int decimalPlace=1;
        while(nums){
            int digit=nums%10;
            int newMap=mapping[digit];
            newNum+=decimalPlace*newMap;

            decimalPlace*=10;
            nums/=10;
        }

        return newNum;
    }

    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<pair<int, int>> v;

        for(int i=0; i<nums.size(); i++){
            int newNum=mapNum(nums[i], mapping);
            v.push_back({newNum, i});
        }

        sort(v.begin(), v.end());

        vector<int> res;
        for(auto &it: v){
            res.push_back(nums[it.second]);
        }

        return res;
    }
};

//---------------------------------------------------------------------------------------------
/* 1. We will take a vector of pairs to store the new mapped number and the original index of it in the nums array.
2. Then in mapNum(), We map the numbers according to the mapping array.
3. Then we sort the nums array.
4. Now we push the original numbers in the res according to the sort v array.
5. Finally, return res. */
