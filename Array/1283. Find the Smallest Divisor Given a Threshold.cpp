//APPROACH 1 (SPACE OPTIMIZED)

class Solution {
public:
    int maxele(vector<int>& nums){
        int maxi=INT_MIN;
        for(int i=0; i<nums.size(); i++){
            maxi=max(maxi,nums[i]);
        }

        return maxi;
    }

    int calculatesum(vector<int> &nums, int mid){
        int sum=0;
        for(int i=0; i<nums.size(); i++){
            sum+=ceil((double)nums[i]/mid);
        }

        return sum;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        ios_base::sync_with_stdio(false);

        int low=1,high=maxele(nums);

        while(low<=high){
            int mid=(low+high)/2;

            int div=calculatesum(nums,mid);
            if(div<=threshold){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }

        return low;
    }
};

//--------------------------------------------------------------------------------
/* 1. We will use binary search, assign low as 1 and high as max element of the array.
2. Then we calculate the sum when all the elements are divided by mid.
3. If sum value is less than or equal to threshold then we update high as mid-1.
4. Else, we update low as mid+1.
5. Finally return low. */

//------------------------------------------------------------------------------------------

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
