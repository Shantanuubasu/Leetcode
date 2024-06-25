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
    bool hasCycle(ListNode *head) {
        ios_base::sync_with_stdio(false);
        if(head==NULL){
            return false;
        }
        ListNode* fast=head;
        ListNode* slow=head;

        while(fast!=NULL && fast->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;

            if(fast==slow){
                return true;
            }
        }

        return false;


    }
};

//----------------------------------------------------------------------
/* 1. In two pointer approach, we define pointer `fast` and `slow`, `fast` covers 2 nodes at time, while `slow` covers only one. If there is a cycle there will a node where both `fast` and `slow` will meet, indicating that there is a cycle.
2. First we check if `head` is `NULL`, if yes, then it is a empty linked list, therefore we return `false`.
3. If not then we will move the `fast` and `slow` pointer, if at any point they meet we return `true`, otherwise, we return `false`. */
