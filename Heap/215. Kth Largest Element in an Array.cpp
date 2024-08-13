class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;

        for(int& i:nums){
            pq.push(i);

            if(pq.size()>k){
                pq.pop();
            }
        }

        return pq.top();
    }
};

//---------------------------------------------------------------------------
/* 1. Take a priority queue, push elements of array in pq.
2. If the size of pq is greater than k then pop.
3. Finally, return pq.top */
