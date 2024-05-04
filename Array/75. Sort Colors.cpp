class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l=0,r=nums.size()-1,mid=0;

        while(mid<=r){
            if(nums[mid]==0){
                swap(nums[l],nums[mid]);
                l++;
                mid++;
            }
            else if(nums[mid]==1){
                mid++;
            }
            else{
                swap(nums[mid],nums[r]);
                r--;
            }
        }
    }
};

//------------------------------------------------------
/* 1. We will take 3 pointers.
2. If we get 0 at mid then we swap it with element at l.
3. If we get 1 then we just increment mid.
4. If we get 2 then we swap mid and r. */
