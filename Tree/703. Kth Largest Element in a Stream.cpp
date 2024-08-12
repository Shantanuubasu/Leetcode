class KthLargest {
public:
    int K;
    priority_queue<int, vector<int>, greater<int>> pq;
    KthLargest(int k, vector<int>& nums) {
        K=k;

        for(int &i: nums){
            pq.push(i);
        
            if(pq.size()>k){
                pq.pop();
            }
        }

    }
    
    int add(int val) {
        pq.push(val);

        if(pq.size()>K){
            pq.pop();
        }

        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */

//-------------------------------------------------------------------------------
/* 1. Define a priority queue which will be min heap.
2. In KthLargest(), push the elements in the priority queue,, if pq's size becomes greater than k then pop.
3. In add(), push the val in pq, if pq's size is greater than k then pop.
4. Finally, return pq.top() */
