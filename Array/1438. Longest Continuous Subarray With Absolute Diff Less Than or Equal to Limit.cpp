class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        ios::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);

        multiset<int> st;

        int i=0,j=0,ans=0;

        while(j<nums.size()){
            st.insert(nums[j]);

            while(*st.rbegin() - *st.begin()>limit){
                st.erase(st.find(nums[i]));
                i++;
            }

            ans=max(ans,j-i+1);
            j++;
        }

        return ans;
    }
};

//--------------------------------------------------------------------------
/* 1. We will use a multiset data structure, we take two pointers i and j.
2. Insert jth element in the multiset, and check the difference between the minimum and maximum element in the multiset.
3. If it is greater than limit then we will shrink the window by removing the ith element from the multiset and increment i.
4. Then we will update ans with maximum of ans or j-i+1 and increment j.
5. Finally, return ans. */
