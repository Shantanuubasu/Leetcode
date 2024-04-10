class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n=deck.size();
        sort(deck.begin(),deck.end());
        vector<int> ans(n);
        queue<int> q;
        int i=0,j=0;

        for(int i=0; i<n; i++){
            q.push(i);
        }

        for(int i=0; i<n; i++){
            int idx=q.front();
            q.pop();
            q.push(q.front());
            q.pop();
            ans[idx]=deck[i];
        }

        return ans;
    }
};

//--------------------------------------------------------------------------------------
//1. Queue can be used easily for this problem, first sort the deck array.
//2. We will pop first and then append the next to the last.
//3. Finally, return ans.
