class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        ios_base::sync_with_stdio(false);

        sort(arr.begin(),arr.end());
        vector<vector<int>> ans;
        int mindiff=INT_MAX;
        for(int i=1; i<arr.size(); i++){
            if(arr[i]-arr[i-1]<mindiff){
                ans.clear();
                mindiff=arr[i]-arr[i-1];
                ans.push_back({arr[i-1],arr[i]});
                continue;
            }
            if(arr[i]-arr[i-1]==mindiff){
                ans.push_back({arr[i-1],arr[i]});
            }
        }

        return ans;

    }
};

//--------------------------------------------------------------------
/* 1. Sort the array.
2. If the difference between the current and previous element is less than mindiff then clear the ans array and update mindiff.
3. If difference is equal to mindiff then add the numbers to the ans.
4. Finally, return ans. */
