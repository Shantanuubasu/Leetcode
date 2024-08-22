class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxind=0;
        for(int i=0; i<nums.size(); i++){
            if(i>maxind){
                return false;
            }

            maxind=max(maxind, nums[i]+i);

            if(maxind>=nums.size()-1){
                return true;
            }
        }

        return true;
    }
};

//--------------------------------------------------------------
/* 1. For each jump we will track the maximum we can jump.
2. So we will update maxind to max of maxind or nums[i]+1.
3. If i is greater than maxind it means i is not reachable so we return false.
4. If at any stage maxind reaches last index then return true. */
