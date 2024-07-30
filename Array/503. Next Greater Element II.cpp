class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        ios_base::sync_with_stdio(false);

        int n=nums.size();
        vector<int> ans;
        stack<int> st;
        for(int i=(2*n)-1; i>=0; i--){
            while(!st.empty() && nums[i%n]>=st.top()){
                st.pop();
            }

            if(i<n){
                if(!st.empty()){
                    ans.push_back(st.top());
                }
                else{
                    ans.push_back(-1);
                }
            }

            st.push(nums[i%n]);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

//-------------------------------------------------------------------
/* 1. As it is a circular array, start iteration from (2*n)-1.
2. Now if the current element is greater than top of the stack then pop from the stack until the condition satisfies.
3. For i<n, if stack is not empty then push into the ans array.
4. Else, push -1 in the ans.
5. Then push current element into the stack.
6. Reverse the ans array.
7. Finally, return ans. */
