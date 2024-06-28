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
    ListNode* deleteMiddle(ListNode* head) {
        ios_base::sync_with_stdio(false);

        if(head->next==NULL){
            return NULL;
        }
        ListNode* slow=head;
        ListNode* fast=head->next->next;
        while(fast!=NULL && fast->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
        }

        slow->next=slow->next->next;

        return head;
    }
};

//--------------------------------------------------------------------
/* 1. If head->next is NULL then return NULL.
2. Take two pointer slow and fast, initialize slow as head and fast as head->next->next.
3. Slow will jump one node at a time and fast will jump two nodes.
4. Now we move slow and fast until fast or fast->next becomes NULL.
5. Now the slow will point to the node previous to the middle node.
6. Now we point slow->next to slow->next->next to delete mid node.
7. Finally return head. */
