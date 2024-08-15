class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size()%groupSize!=0){
            return false;
        }


        priority_queue<int, vector<int>, greater<int>> pq;

        for(int i=0; i<hand.size(); i++){
            pq.push(hand[i]);
        }

        int gsize=0;
        int prev=-1;
        vector<int> temp;


        while(!pq.empty()){
            if(gsize==groupSize){
                for(int i:temp){
                    pq.push(i);
                }
                prev=-1;
                temp.clear();
                gsize=0;
            }

            int curr=pq.top();
            pq.pop();
            if(prev==curr){
                temp.push_back(curr);
            }
            else if(prev==-1 || prev+1==curr){
                prev=curr;
                gsize++;
            }
            else{
                return false;
            }

        }

        return temp.empty() ? true : false; 
    }
};

//----------------------------------------------------------------
/* 1. If the size of hand is not divisible by groupSize then we cannot form groups so we return false.
2. Take a priority queue, a min heap and push all the contents of hand in it.
3. Now we define some variables gsize will keep track of current group size and prev to keep track of previous element inserted in the group. Also, temp array will store any duplicates when we will form groups.
4. Now till the pq is not empty, we pop the top element from pq, store this top element in curr.
5. If prev is equal to curr, we push it into temp as it is a duplicate, we only needd consecutive numbers.
6. If prev is -1 or prev+1 is equal to curr then we can form a group so we assign prev to curr and increment gsize.
7. Else, we cannot form a group so we return false.
8. Now when gsize is equal to groupSize then we push all the duplicates in temp to pq again.
9. As we will start a new group now, update prev to -1, clear temp and make gsize as 0.
10. Finally, when pq is empty, we check if temp is empty, if yes then we have formed all group so we return true. If not, then we have some remaining elements in temp, so we return false. */
