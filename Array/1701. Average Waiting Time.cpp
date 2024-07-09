class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        ios_base::sync_with_stdio(false);

        long long int prev=0;
        long long int totalWait=0;
        for(vector<int> &v:customers){
            int arrival=v[0];
            int wait=v[1];

            if(arrival<prev){
                prev=prev+wait;
            }
            else{
                prev=arrival+wait;
            }

            totalWait+=prev-arrival;
        }

        return (totalWait*1.0/customers.size()*1.0);
    }
};

//-------------------------------------------------------------------------
/* 1. We will keep track the completion of last order.
2. If the arrival of new customer is less than the completion of previous order then his order will complete in prev+wait time.
3. If there is not order currently then, he would have to wait for arrival+wait time.
4. Total Wait time for an individual would be completion of previous order minus arrival of his, i.e, prev-arrival.
5. Finally we return the average of total wait time by dividing it by the size of customers array. */
