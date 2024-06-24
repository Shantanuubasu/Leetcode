class Solution {
public:
    int minOperations(vector<int>& nums) {
        ios_base::sync_with_stdio(false);

        if(nums.size()<3){
            return -1;
        }
        int c=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==0 && i+2<nums.size()){
                nums[i]=1-nums[i];
                nums[i+1]=1-nums[i+1];
                nums[i+2]=1-nums[i+2];
                c++;
            }
        }

        for(int i=0; i<nums.size(); i++){
            if(nums[i]==0){
                return -1;
            }
        }

        return c;
    }
};

//--------------------------------------------------------------
/* 1. If the size of nums array is less than 3 then we return -1 as minimum value of window should be 3.
2. We iterate in the nums array check if nums[i] is 0 or not, if yes then we flip i, i+1, i+2 elements and keep a track the number of times we perform this operation in c.
3. Then finally we check if there is any zeros left in the array, if yes then we return -1.
4. Else, we return c. */
