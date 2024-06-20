class Solution {
public:
    bool countBalls(vector<int> &position, int mid, int m){
        int c=1;
        int dist=position[0];
        for(int i=1; i<position.size(); i++){
            if(position[i]-dist>=mid){
                c++;
                dist=position[i];
            }
            if(c>=m){
                return true;
            }
        }
        return false;
    }

    int maxDistance(vector<int>& position, int m) {
        ios_base::sync_with_stdio(false);

        sort(position.begin(),position.end());
        int low=0,high=1e9;
        while(low<=high){
            int mid=low+(high-low)/2;

            if(countBalls(position,mid,m)){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }

        return high;
    }
};

//-------------------------------------------------------------------
/* 1. Sort the position array.
2. Now take low as 0 and high as 1e9 as per the constraints.
3. Calculate mid and find how many balls can be accomodated in mid distance.
4. If the count of balls accomodated is more than m then we need to increase the space between the balls so update low as mid+1.
5. Else, update high as mid-1.
6. Finally, return high. */
