class Solution {
public:
    int jump(vector<int>& nums) {
        int l=0, r=0, ans=0;

        while(r<nums.size()-1){
            int dist=0;
            for(int i=l; i<=r; i++){
                dist=max(dist, i+nums[i]);
            }

            l=r+1;
            r=dist;
            ans++;
        }

        return ans;
    }
};

//---------------------------------------------------------------
/* 1. We will track the range in which we can jump for a given index.
2. So we update dist to max of dist or i+nums[i].
3. Now update l to r+1 as the least we can make is 1 jump.
4. Update r to dist which is the max number of jump for given index.
5. Increment the ans by 1.
6. Finally, return ans. */
