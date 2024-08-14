/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> pq;

        for(int i=0; i<lists.size(); i++){
            if(lists[i]!=nullptr){
                pq.push({lists[i]->val, lists[i]});
            }
        }

        ListNode* dummyHead= new ListNode(-1);
        ListNode* h=dummyHead;

        while(!pq.empty()){
            auto temp=pq.top();
            pq.pop();

            int d=temp.first;
            ListNode* n=temp.second;

            if(n->next){
                pq.push({n->next->val, n->next});
            }

            h->next=n;
            h=h->next;
        }

        return dummyHead->next;
    }
};

//-------------------------------------------------------------------
/* 1. Take a priority queue with int and ListNode as its input type.
2. Add the head of each list in the priority queue with its node value.
3. Now create a dummy head which will contain the answer list.
4. Now pop one entry from pq, push the next node if it is not null.
5. Then, add the popped node to answer list.
6. Finally, return dummyHead->next. */
