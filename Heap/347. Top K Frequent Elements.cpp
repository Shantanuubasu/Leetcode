class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        unordered_map<int, int> mp;

        for(int i:nums){
            mp[i]++;
        }

        for(auto it: mp){
            pq.push({it.second, it.first});

            if(pq.size()>k){
                pq.pop();
            }
        }

        vector<int> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};

//-----------------------------------------------------------------
/* 1. Take a hash table and add all the elements of nums along with its frequency.
2. Now push the frequency along with the element in the priority queue, if the size of pq is greater than k then pop from it.
3. Add all the elements remaining in pq to ans. 
4. Finally, return ans. */
