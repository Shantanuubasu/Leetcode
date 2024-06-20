class Solution {
public:
    bool countTime(vector<int> &dist, double hour, int mid){
        double time=0.0;
        double buffer=0.0;
        for(int i=0; i<dist.size()-1; i++){
            time+=ceil((dist[i]/(mid*1.0)));
        }
        time+=(double)dist[dist.size()-1]/mid;

        return time<=hour;
    }

    int minSpeedOnTime(vector<int>& dist, double hour) {
        ios_base::sync_with_stdio(false);

        int low=1,high=1e7;
        if(hour<=dist.size()-1){
            return -1;
        }
        while(low<=high){
            int mid=low+(high-low)/2;

            if(countTime(dist, hour, mid)){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }

        return low;
    }
};

//---------------------------------------------------------------
/* 1. We take low as 1 and high as 1e7 (taking high as 1e7 for one of the testcase that goes for 10000000).
2. If hour is less than or equal to the size of dist array then return -1.
3. Now calculate mid and for mid speed calculate the time taken.
4. If time taken is less than the hour then update high as mid-1.
5. Else, update low as mid+1.
6. Finally, return low. */
