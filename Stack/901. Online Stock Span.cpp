class StockSpanner {
public:
    stack<pair<int,int>> st;
    int ind=-1;
    StockSpanner() {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        
        ind=-1;
    }
    
    int next(int price) {
        ind+=1;
        while(!st.empty() && st.top().first<=price){
            st.pop();
        }

        int ans=ind-(st.empty() ? -1 : st.top().second);

        st.push({price, ind});

        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */

//-----------------------------------------------------------------------------------
/* 1. Take a pair stack annd ind as -1.
2. In StockSpanner(), initialize ind as -1.
3. In next(), Increment ind first and then pop till top element is less than price.
4. ans will be ind minus the second value of top of the stack or if stack is empty then -1.
5. Then we push price with ind.
6. Finally, return ans. */
