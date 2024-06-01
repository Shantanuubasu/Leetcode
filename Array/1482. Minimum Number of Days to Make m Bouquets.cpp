class Solution {
public:
    bool countDays(vector<int>& bloomDay, int mid, int m, int k){
        int c=0;
        long int b=0;
        for(int i=0; i<bloomDay.size(); i++){
            if(bloomDay[i]<=mid){
                c++;
            }
            else{
                b+=(c/k);
                c=0;
            }
        }
        b+=(c/k);
        if(b>=m){
            return true;
        }

        return false;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        ios_base::sync_with_stdio(false);

        int maxi=INT_MIN;
        int mini=INT_MAX;
        for(int i=0; i<bloomDay.size(); i++){
            maxi=max(maxi,bloomDay[i]);
            mini=min(mini,bloomDay[i]);
        }

        int low=mini,high=maxi;
        int n=bloomDay.size();

        if((long)m*k>n){
            return -1;
        }

        while(low<=high){
            int mid=low+(high-low)/2;

            if(countDays(bloomDay,mid,m,k)){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }


        return low;
    }
};

//-------------------------------------------------------------------
/* 1. We will use binary search, initialize low and high with min and max element of the array respectively.
2. We need m*k flowers if array size n is less than that we will return -1 as not enough flowers are available.
3. We calculate mid and use countDays function to check if on the mid day can we make required number of bouquets or not.
4. If yes return true and update high to mid-1 to search for a lesser value.
5. Else update low to mid+1 to search for a higher value.
6. Finally return low. */
