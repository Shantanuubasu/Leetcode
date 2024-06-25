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
    ListNode* reverseList(ListNode* head) {
        if (head==NULL){
            return NULL;
        }
        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* nxt;

        while(curr!=NULL){
            nxt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
        }

        return prev;
    }
};

//-------------------------------------------------------------
/* 1. We will first check if `head` is empty, if yes then we return `NULL`.
2. Otherwise, we use 3 pointer approach, `curr` pointer points at current node, `prev` points to node before `curr`, and `nxt` points to node after `curr`.
3. Now will traverse in the list, we will connect `curr` node to `prev` node and update `prev` to `curr` and `curr` to `nxt`.
4. We finally return `prev`. */
