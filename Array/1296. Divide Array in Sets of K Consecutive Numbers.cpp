// APPROACH 1 (SPACE OPTIMIZED)

class Solution {
public:
    bool validSet(vector<int> &nums, int k, int i ,int n){
        int next=nums[i]+1;
        nums[i]=-1;
        int c=1;
        ++i;
        while(i<n && c<k){
            if(nums[i]==next){
                next=nums[i]+1;
                nums[i]=-1;
                ++c;
            }
            ++i;
        }

        return c==k;
    }

    bool isPossibleDivide(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false);
    
        int n=nums.size();
        if(n%k!=0){
            return false;
        }
        sort(nums.begin(),nums.end());

        for(int i=0; i<n; i++){
            if(nums[i]>=0){
                if(!validSet(nums,k,i,n)){
                    return false;
                }
            
            }
        }

        return true;
    }
};

//---------------------------------------------------------------
/* 1. First we wil sort the nums array.
2. Then we check for every element which is greater than or equal to 0, if they could form a valid group.
3. In validSet(), we take the next element needed and make nums[i]=-1 because we have used up that element in the other group.
4. Now check if there is any element available which is equal to next.
5. Keep checking till we reach end of the array or we complete the k needed.
6. Check if the group formed is equal to k needed.
7. If true then we start forming next group, otherwise we return false. */
//----------------------------------------------------------------------------------------------------------------------------------


//APPROACH 2 (MAP)


class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false);

        if(nums.size()%k!=0){
            return false;
        }
        map<int,int> mp;
        for(int& i:nums){
            mp[i]++;
        }

        while(mp.size()!=0){
            int start=mp.begin()->first;
            int next=start+1;
            mp[start]--;
            int c=1;
            if(mp[start]==0){
                mp.erase(start);
            }

            while(c<k){
                if(mp.find(next)==mp.end()){
                    return false;
                }
                ++c;
                mp[next]--;
                if(mp[next]==0){
                    mp.erase(next);
                }
                next=next+1;
            }

        }
        
        return true;
    }
};

//------------------------------------------------------------------------
/* 1. Take a map and store all the numbers along with their frequencies in the map.
2. Now take the first element of the map and find the next element to be included from it.
3. Decrement the frequency of start as we have taken it in the group and if frequency becomes 0 then remove it from the map.
4. Take a variable c to keep track of number of elements in the map.
5. Now find the next element in the map, if not found return false.
6. Else increment c and decrement frequency of next.
7. If the frequency of next becomes 0 then remove it from the map.
8. Update next to next+1.
9. Return true when all the sets are formed. */

