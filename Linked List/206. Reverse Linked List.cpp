//APPROACH - 1 - ITERATIVE

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

//--------------------------------------------------------------------------------------------------------------------------------------------------------------

// APPROACH - 2 - RECURSIVE

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
    ListNode* reverse(ListNode* head){
        if(head==NULL || head->next==NULL){
            return head;
        }

        ListNode* newhead=reverse(head->next);
        ListNode* temp=head->next;
        temp->next=head;
        head->next=NULL;
        return newhead;
    }
    ListNode* reverseList(ListNode* head) {
        ios_base::sync_with_stdio(false);

        ListNode* n=reverse(head);
        
        return n;
    }
};

//--------------------------------------------------------------
/* 1. If we get head or head->next as NULL then return head.
2. Otherwise we take a newhead and  call reverse on head->next recursively.
3. Take temp as head->next and make temp->next as head.
4. head->next as NULL.
5. Finally, return newhead. */
