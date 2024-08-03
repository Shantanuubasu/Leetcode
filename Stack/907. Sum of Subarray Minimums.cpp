class Solution {
public:
    vector<int> NSE(vector<int> arr){
        ios_base::sync_with_stdio(false);

        stack<int> st;
        vector<int> nse(arr.size());

        for(int i=arr.size()-1; i>=0; i--){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }            

            nse[i]=st.empty() ? arr.size() : st.top();

            st.push(i);
        }

        return nse;
    }

    vector<int> PSE(vector<int> arr){
        vector<int> pse(arr.size());
        stack<int> st;

        for(int i=0; i<arr.size(); i++){
            while(!st.empty() && arr[st.top()]>arr[i]){
                st.pop();
            }            

            pse[i]=st.empty() ? -1 : st.top();

            st.push(i);
        }

        return pse;
    }

    int sumSubarrayMins(vector<int>& arr) {
        int mod=1e9+7;
        int total=0;
        vector<int> nse=NSE(arr);
        vector<int> pse=PSE(arr);

        for(int i=0; i<arr.size(); i++){
            int left=i-pse[i];
            int right=nse[i]-i;

            total=(total+ (left*right*1LL*arr[i]))%mod;
        }

        return total;
    }
};

//----------------------------------------------------------------------
/* 1. We will use the concept of next smallest element and previous smallest element.
2. First we will find the nse ans pse of the array elements and store it into their respective array.
3. Now the number of subarray from left of the element will be i-pse[i].
4. and the number of subarray from left will be nse[i]-i.
5. So the total will be left * right * arr[i] contributions. and use mod to format the answer.
6. Finally, return total. */
