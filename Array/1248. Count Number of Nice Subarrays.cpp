class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false);

        int prev=0,oddcount=0,ans=0;
        int i=0,j=0;

        while(j<nums.size()){
            if(nums[j]%2!=0){
                oddcount++;
                prev=0;
            }

            while(oddcount==k){
                prev++;

                if(nums[i]%2!=0 && i<nums.size()){
                    oddcount--;
                }
                i++;
            }
            j++;
            ans+=prev;
        }

        return ans;
    }
};

//-------------------------------------------------------------------------
/* 1. We will take two pointer i and j, if we get odd at jth pointer increment oddcount.
2. If oddcount is equal to k then increment prev which stores the current number of window.
3. and increment i and decrement oddcount if element at ith index is odd.
4. Add the prev to ans and increment j.
5. Finally, return ans. */
