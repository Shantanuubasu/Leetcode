class Solution {
public:
    int maxele(vector<int>& piles){
        int maxi=INT_MIN;
        for(int i=0; i<piles.size(); i++){
            maxi=max(maxi,piles[i]);
        }

        return maxi;
    }

    long long f(vector<int>& piles, int mid){
        long long hours =0;
        for(int i = 0; i < piles.size(); i++){
            hours += ceil((  (double)piles[i]  /   (double)mid));
        }
        return hours;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        ios_base::sync_with_stdio(false);

        int low=1,high=maxele(piles);
        while(low<=high){
            int mid=(low+high)/2;
            long long hours=f(piles,mid);
            if(hours<=h){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }

        return low;
    }
};

//----------------------------------------------------------------------
/* 1. We will use binary search for this problem, assign low as 1 and high as maximum element of the array.
2. calculate mid and find the numbers of hours taken according to the mid value.
3. If hours is less than or equal to h then update high as mid-1.
4. Otherwise, update low as mid+1.
5. Finally, return low. */
