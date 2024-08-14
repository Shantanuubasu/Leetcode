class Solution {
public:
    int countPairs(vector<int> &nums, int mid){
        int i=0,j=0;
        int c=0;
        for(int i=0; i<nums.size(); i++){
            while(j<nums.size() && nums[j]-nums[i]<=mid){
                j++;
            }

            c+=j-i-1;
        }

        return c;
    }

    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int low=0, high=nums[nums.size()-1]-nums[0];

        while(low<high){
            int mid=low+(high-low)/2;
            if(countPairs(nums, mid)<k){
                low=mid+1;
            }
            else{
                high=mid;
            }
        }

        return low;
    }
};

//---------------------------------------------------------------------------------
/* 1. To solve the problem, we are gonna use binary search on answers.
2. So first we sort the array nums.
3. Now take low and a high pointer, initialize low to 0 and high to last element of array minus first element of array.
4. Now find the mid and check the number of pairs in the array with difference less than mid using countPairs().
5. In countPairs(), Start i from 0 to go till nums' size and take a j pointer to move till either it reaches end of array or till the differene between the ith and jth element is less than or equal to mid.
6. Now the count of pairs to c which will be j-i-1.
7. If the count of pairs is less than k then we need more pairs so we increase the difference value by updating low to mid+1.
8. If number of pairs is more than k then we need lesser pairs so we decrease the difference by updating high to mid.
9. Finally, we will have the answer at low. So, return low. */
