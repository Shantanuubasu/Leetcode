class Solution {
public:
    int minDifference(vector<int>& nums) {
        ios_base::sync_with_stdio(false);

        int res=INT_MAX;
        int n=nums.size();

        if(n<=4){
            return 0;
        }

        sort(nums.begin(), nums.end());

        res=min(res, nums[n-4]-nums[0]);
        res=min(res, nums[n-1]-nums[3]);
        res=min(res, nums[n-3]-nums[1]);
        res=min(res, nums[n-2]-nums[2]);

        return res;
    }
};

//---------------------------------------------------------
/* 1. If the size of array is less than or equal to 4 then return 0 as all the numbers can be made equal.
2. Sort the array and only 4 possible answers can be formed.
3. First, we make last 3 elements as n-4th element.
4. Second, we make first 3 element as 4th element.
5. Third, we make last two element as n-3th element and first element as element at index 1.
6. Fourth, we make last element as n-2th element and first two element as 3rd element.
7. Finally, return res. */
