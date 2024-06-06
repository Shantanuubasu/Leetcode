class Solution {
public:
    bool validSet(vector<int> &nums, int k, int i ,int n){
        int next=nums[i]+1;
        nums[i]=-1;
        int c=1;
        ++i;
        while(i<n && c<k){
            if(nums[i]==next){
                next=nums[i]+1;
                nums[i]=-1;
                ++c;
            }
            ++i;
        }

        return c==k;
    }

    bool isPossibleDivide(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false);
    
        int n=nums.size();
        if(n%k!=0){
            return false;
        }
        sort(nums.begin(),nums.end());

        for(int i=0; i<n; i++){
            if(nums[i]>=0){
                if(!validSet(nums,k,i,n)){
                    return false;
                }
            
            }
        }

        return true;
    }
};

//---------------------------------------------------------------
/* 1. First we wil sort the nums array.
2. Then we check for every element which is greater than or equal to 0, if they could form a valid group.
3. In validSet(), we take the next element needed and make nums[i]=-1 because we have used up that element in the other group.
4. Now check if there is any element available which is equal to next.
5. Keep checking till we reach end of the array or we complete the k needed.
6. Check if the group formed is equal to k needed.
7. If true then we start forming next group, otherwise we return false. */
