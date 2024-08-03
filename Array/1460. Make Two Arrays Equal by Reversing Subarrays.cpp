class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int, int> mp;

        for(int i:arr){
            mp[i]++;
        }

        for(int i:target){
            if(mp.find(i)==mp.end()){
                return false;
            }
            mp[i]--;
            if(mp[i]==0){
                mp.erase(i);
            }
        }

        return true;
    }
};

//----------------------------------------------------------------------------------
/* 1. We will take a map to store the element along with their count from the arr array.
2. Then we will iterate in the target array and if the element is not found the map then return false.
3. Otherwise, we decrement the element's count and if count becomes 0 then erase the element from the map.
4. Finally, return true. */
