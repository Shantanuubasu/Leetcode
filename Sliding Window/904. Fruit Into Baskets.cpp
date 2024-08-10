class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int i=0, j=0;
        int ans=0;
        unordered_map<int, int> mp;
        while(j<fruits.size()){
            mp[fruits[j]]++;
            while(mp.size()>2){
                mp[fruits[i]]--;
                if(mp[fruits[i]]==0){
                    mp.erase(fruits[i]);
                }
                i++;
            }

            ans=max(ans, j-i+1);

            j++;
        }

        return ans;
    }
};

//------------------------------------------------------------
/* 1. Take two pointers i and j, start both from 0.
2. Now add the element at j to map and check if the map size is greater than 2.
3. If yes, then decrement the count of element at i from map and if the count becomes 0 then erase that element from map and increment i.
4. Now update ans to maximum of ans or j-i+1 and increment j.
5. Finally, return ans. */
