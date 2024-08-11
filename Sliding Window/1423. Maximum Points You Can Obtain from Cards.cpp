class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int lsum=0, rsum=0;
        int maxsum=0;

        for(int i=0; i<k; i++){
            lsum+=cardPoints[i];
        }

        maxsum=lsum;

        int rind=cardPoints.size()-1;
        for(int i=k-1; i>=0; i--){
            lsum-=cardPoints[i];
            rsum+=cardPoints[rind];
            rind--;

            maxsum=max(maxsum, lsum+rsum);
        }

        return maxsum;
    }
};

//--------------------------------------------------------
/* 1. Lets first take all the k elements from left, so maxsum will be equal to lsum.
2. Now lets start taking 1 element from right of the array and keep updating maxsum to max of maxsum or lsum+rsum.
3. Finally, return maxsum. */
