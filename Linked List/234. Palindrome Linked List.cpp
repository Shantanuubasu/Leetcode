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
        ListNode* front=head->next;
        front->next=head;
        head->next=NULL;
        return newhead;

    } 

    bool isPalindrome(ListNode* head) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        if(head==NULL && head->next==NULL){
            return true;
        }

        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }

        ListNode* newhead=reverse(slow->next);
        ListNode* first=head;
        ListNode* second=newhead;
        while(second!=NULL){
            if(first->val!=second->val){
                reverse(newhead);
                return false;
            }
            first=first->next;
            second=second->next;
        }
        reverse(newhead);
        return head;
    }
};

//---------------------------------------------------------------------------
/* 1. We start by finding the middle node of the list by using slow and fast pointers.
2. Then we reverse the 2nd half of the list and start comparing the values of the second half to the first.
3. If value does not match then we return false. Otherwise, we return head.
4. To reverse the list we use recurrsive approach. */
