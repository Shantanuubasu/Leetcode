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
        ListNode* curr=head;
        ListNode* prev=nullptr;

        while(curr!=nullptr){
            ListNode* nxt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
        }

        return prev;
    }

    ListNode* removeNodes(ListNode* head) {
        ios_base::sync_with_stdio(0);
        ListNode* revhead=reverse(head);

        ListNode* curr=revhead;
        ListNode* prev=nullptr;
        int max=INT_MIN;
        while(curr!=nullptr){
            if(curr->val<max){
                prev->next=curr->next;
            }
            else{
                max=curr->val;
                prev=curr;
            }
            curr=curr->next;
        }        

        ListNode* newhead=reverse(revhead);
        return newhead;
    }
};

//------------------------------------------------------------------
/* 1. We will reverse the list.
2. Then we will traverse in reversed list and if any element is less than max value we will delete that node.
3. Then reverse the list again.
4. return the head. */
