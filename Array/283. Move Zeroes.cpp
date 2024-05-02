class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int i=0,j=0;
        while(j<nums.size()){
            if(nums[j]!=0){
                nums[i++]=nums[j];
            }
            j++;
        }

        for(int j=i; j<nums.size(); j++){
            nums[j]=0;
        }
    }
};

//--------------------------------------------------------------
/* 1. Ignore the zeros in the array and move all the non-zero elements together.
2. In the remaining indexes enter 0. */
