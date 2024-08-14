class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        if(arr.empty()){
            return {};
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        for(int i=0; i<arr.size(); i++){
            pq.push({arr[i], i});
        }

        int rank=1;
        int prev=pq.top().first;
        while(!pq.empty()){
            auto temp=pq.top();
            pq.pop();
            int ele=temp.first;
            int idx=temp.second;
            if(ele>prev){
                rank++;
            }
            arr[idx]=rank;
            prev=ele;
        }

        return arr;
    }
};

//--------------------------------------------------------------------
/* 1. If the array is empty then return empty arr.
2. Take a priority queue, push all the elements along with its index.
3. Now we will increase the rank only when we get an element which is greater than previous element.
4. Add the ranks of element according to its position in original array.
5. Finally, return arr. */
