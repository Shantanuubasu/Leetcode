class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int i=0,j=nums.size()-1;
        int c=0;
        while(i<j){
            if(nums[i]+nums[j]<target){
                c+=j-i;
                i++;
            }
            else{
                j--;
            }
        }

        return c;
    }
};

//--------------------------------------------------------------------
/* 1. Sort the array.
2. Take a pointer from index 0 and another from index n-1.
3. Now if the sum of elements at i and j is less than target then add j-i to the c as all the combinations betweene j and i will satisfy the condition and increment i.
4. Else, decrement j.
5. Finally, return c. */
