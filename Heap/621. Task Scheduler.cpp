class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> v(26,0);
        int ans=0;
        for(char ch:tasks){
            v[ch-'A']++;
        }

        priority_queue<int> pq;
        for(int i=0; i<v.size(); i++){
            if(v[i]>0){
                pq.push(v[i]);
            }
        }

        while(!pq.empty()){
            vector<int> temp;

            for(int i=0; i<n+1; i++){
                if(!pq.empty()){
                    temp.push_back(pq.top()-1);
                    pq.pop();
                }
            }

            for(int i:temp){
                if(i>0){
                    pq.push(i);
                }
            }

            if(pq.empty()){
                ans+=temp.size();
            }
            else{
                ans+=n+1;
            }
        }

        return ans;
    }
};

//------------------------------------------------------------
/* 1. First of all store the frequency of each character in a array of size 26.
2. Now push the frequencies of character in priority queue which have frequency greater than 0.
3. Now take a temp array, we will divide the problem in the segments of n+1.
4. Now for n+1 times, push the (top element-1) of pq in temp array and then pop the element.
5. Now the push the elements from temp having value greater than 0 to pq.
6. If pq is empty then we add temp's size to ans, otherwise add n+1.
7. Finally, return ans. */
