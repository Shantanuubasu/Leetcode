class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> candy(ratings.size(), 1);

        for(int i=1; i<ratings.size(); i++){
            if(ratings[i-1]<ratings[i]){
                candy[i]=candy[i-1]+1;
            }
        }

        for(int i=ratings.size()-2; i>=0; i--){
            if(ratings[i]>ratings[i+1]){
                candy[i]=max(candy[i], candy[i+1]+1);
            }
        }

        int ans=0;
        for(int i:candy){
            ans+=i;
        }

        return ans;
    }
};

//-----------------------------------------------------------------------------
/* 1. In the first pass we will compare the element with its previous element. If the rating of current element is greater than previous then assign one candy more than the previous one.
2. In second pass, We will compare the current element with its next one, so if the current's rating is more then assign max of current candy or one more than next one's.
3. Finally, sum all the candies and return ans. */
