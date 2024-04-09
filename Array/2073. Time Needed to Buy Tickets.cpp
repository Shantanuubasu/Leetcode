class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int t=0;

        for(int i=0; i<tickets.size(); i++){
            t+=min(tickets[i],tickets[k]);
            if(i>k && tickets[i]>=tickets[k]){
                t--;
            }
        }

        return t;
    }
};

//---------------------------------------------------------------------------------------------------------
//1. We will traverse in the tickets array and add the minimum of tickets[i] and tickets[k] to t. As the minimum of the two will exhaust first.
//2. For people which are after k in the line and with greater value than tickets[k] will get one less ticket as k gets exhausted. So, we will decrement the value of t for them.
