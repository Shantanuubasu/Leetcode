class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        ios_base::sync_with_stdio(false);

        int n=profits.size();
        vector<pair<int,int>> v(n);
        for(int i=0; i<n; i++){
            v[i]={capital[i],profits[i]};
        }
        sort(v.begin(),v.end());

        priority_queue<int> pq;
        int i=0;

        while(k--){
            while(i<n && v[i].first<=w){
                pq.push(v[i].second);
                i++;
            }

            if(pq.empty()){
                break;
            }

            w+=pq.top();
            pq.pop();
        }

        

        return w;
    }
};

//-----------------------------------------------------------------
/* 1. Take a vector of pairs to store the capital and its corresponding profit.
2. Now sort this vector.
3. Now iterate for k times and find the elements with capital less than or equal to w and push its corresponding profit into the priority queue.
4. If priority queue is empty we will break.
5. Add the top of top element of the priority queue to w as top element will be the maximum profit we need.
6. Now remove this top element from the priority queue using pop.
7. Finally, return w. */
