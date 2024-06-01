class Solution {
public:
    bool countDays(vector<int> &weights, int days, int mid){
        int x=0;
        int d=0;
        for(int i=0; i<weights.size(); i++){
            if(x+weights[i]>mid){
                d++;
                x=weights[i];
                continue;
            }
            x+=weights[i];
        }
        d+=1;
        if(d<=days){
            return true;
        }
        return false;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        ios_base::sync_with_stdio(false);

        int maxi=INT_MIN;
        int sum=0;

        for(int i=0; i<weights.size(); i++){
            maxi=max(maxi,weights[i]);
            sum+=weights[i];
        }

        int low=maxi,high=sum;

        while(low<=high){
            int mid=low+ (high-low)/2;

            if(countDays(weights,days,mid)){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }

        return low;
    }
};

//------------------------------------------------------------------------
/* 1. We will use binary search, initialize low and high as max element and total sum of the array respectively.
2. We will calculate the mid and calculate the number of days it will take the shipments, if mid is the capacity of the ship.
3. If it is less than or equal to days then we try for lesser capacity so we update high as mid-1.
4. Else we update low as mid+1.
5. Finally return low. */
