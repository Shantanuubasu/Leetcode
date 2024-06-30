/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ios_base::sync_with_stdio(false);

        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(fast==slow){
                slow=head;
                while(slow!=fast){
                    slow=slow->next;
                    fast=fast->next;
                }
                return slow;
            }
        }
        return NULL;
    }
};

//-----------------------------------------------------------
/* 1. Take two pointers slow and fast, slow will move 1 node and fast will move 2 nodes.
2. If fast and slow collide then make slow as head of list and move slow and fast at same speed of 1 node.
3. Then return slow.
4. If there is no loop then we return NULL. */
