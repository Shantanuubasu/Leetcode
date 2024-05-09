class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        
        sort(happiness.begin(),happiness.end(),greater<int>());
        long long int sum=0,i=0;
        while(k--){
            int x=happiness[i]-i;
            if(x>=0){
                sum+=x;
            }
            i++;
        }

        return sum;
    }
};

//---------------------------------------------------------------------------------
/* 1. First we will sort the array in descending order.
2. Then we will run a loop for k times and pick the element from the sorted array and check if isn't a negative.
3. If not then add to the sum.
4. Finally return sum. */
