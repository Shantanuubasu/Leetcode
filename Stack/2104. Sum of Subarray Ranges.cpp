class Solution {
public:
    vector<int> PSE(vector<int> &nums){
        vector<int> pse(nums.size(),0);
        stack<int> st;

        for(int i=0; i<nums.size(); i++){
            while(!st.empty() && nums[st.top()]>nums[i]){
                st.pop();
            }

            pse[i]=st.empty() ? -1 : st.top();

            st.push(i);
        }

        return pse;
    }

    vector<int> NSE(vector<int> &nums){
        vector<int> nse(nums.size(),0);
        stack<int> st;

        for(int i=nums.size()-1; i>=0; i--){
            while(!st.empty() && nums[st.top()]>=nums[i]){
                st.pop();
            }

            nse[i]=st.empty() ? nums.size() : st.top();

            st.push(i);
        }

        return nse;
    }

    vector<int> PGE(vector<int> &nums){
        vector<int> pge(nums.size(),0);
        stack<int> st;

        for(int i=0; i<nums.size(); i++){
            while(!st.empty() && nums[st.top()]<nums[i]){
                st.pop();
            }

            pge[i]=st.empty() ? -1 : st.top();

            st.push(i);
        }

        return pge;
    }

    vector<int> NGE(vector<int> &nums){
        vector<int> nge(nums.size(),0);
        stack<int> st;

        for(int i=nums.size()-1; i>=0; i--){
            while(!st.empty() && nums[st.top()]<=nums[i]){
                st.pop();
            }

            nge[i]=st.empty() ? nums.size() : st.top();

            st.push(i);
        }

        return nge;
    }

    long long subArrayRanges(vector<int>& nums) {
        int n=nums.size();

        vector<int> pse=PSE(nums);
        vector<int> nse=NSE(nums);

        vector<int> pge=PGE(nums);
        vector<int> nge=NGE(nums);

        long long largeSum=0, smallSum=0;
        for(int i=0; i<n; i++){
            long long int left=i-pse[i];
            long long int right=nse[i]-i;
            smallSum+=(left*right*nums[i]);

            long long left2=i-pge[i];
            long long right2=nge[i]-i;
            largeSum+=(left2*right2*nums[i]);
        }

        return abs(largeSum-smallSum);
    }
};

//-------------------------------------------------------------
/* 1. First we find the previous smaller element, next smaller element, previous greater element and next greater element.
2. Then We calculate the contributions of each element, so we find the smallSum and largeSum.
3. Finally, return difference of smallSum and largeSum. */
