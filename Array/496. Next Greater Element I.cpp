class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        ios_base::sync_with_stdio(false);

        unordered_map<int, int> mp;
        stack<int> st;
        for(int i=nums2.size()-1; i>=0; i--){
            while(!st.empty() && nums2[i]>st.top()){
                st.pop();
            }
            if(!st.empty()){
                mp[nums2[i]]=st.top();
            }
            else{
                mp[nums2[i]]=-1;
            }
            st.push(nums2[i]);
        }

        vector<int> ans;

        for(int i=0; i<nums1.size(); i++){
            ans.push_back(mp[nums1[i]]);
        }

        return ans;
    }
};

//-----------------------------------------------------------------
/* 1. We will iterate in nums2 and we will check if the top of the stack is smaller than the current element.
2. If yes then keep popping till we get a number greater than current element or the stack becomes empty.
3. If the stack is not empty then the next greater element would be top of the stack. So we add it to the map.
4. Else, if the stack is empty it means there is no next greater element so we assign -1 to it.
5. Also, push the current element into the stack.
6. Now, iterate in the nums1 and push the value assign to current element into ans.
7. Finally, return ans. */
