class Solution {
public:
    int maxProfit(vector<int>& prices) {
        cin.tie(nullptr)->sync_with_stdio(false);

        int max_profit=0,cheapest=prices[0];
        for(int i=0; i<prices.size(); i++){
            if(prices[i]<cheapest){
                cheapest=prices[i];
            }
            else{
                if(prices[i]-cheapest>max_profit){
                    max_profit=prices[i]-cheapest;
                }
            }
        }
        return max_profit;
    }
};

//-----------------------------------------------------------
/* 1. We find the minimum element in the array.
2. Find the maximum difference with repsect to current element and lowest element.
3. Return max. */
