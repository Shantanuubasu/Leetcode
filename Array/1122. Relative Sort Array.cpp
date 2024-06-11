class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        ios_base::sync_with_stdio(false);

        map<int,int> mp;
        for(int &i: arr1){
            mp[i]++;
        }

        vector<int>ans;
        for(int i=0; i<arr2.size(); i++){
            if(mp.find(arr2[i])!=mp.end()){
                while(mp[arr2[i]]--){
                    ans.push_back(arr2[i]);
                }
                mp.erase(arr2[i]);
            }
        }

        for(auto &it: mp){
            while(it.second>0){
                ans.push_back(it.first);
                mp[it.first]--;
            }
        }

        return ans;
    }
};

//----------------------------------------------------------------
/* 1. We take a map to store the elements with its frequency of arr1.
2. Now iterate in arr2, find if the same element is present in map or not.
3. If yes, then push it into the ans array, its frequency number of times and then erase it from the map.
4. Now iterate in the map and push the remaining elements in the ans array.
5. Finally return ans. */
