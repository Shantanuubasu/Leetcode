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
    ListNode* partition(ListNode* head){
        ListNode* prev=head;
        ListNode* slow=head;
        ListNode* fast=head;

        while(fast!=NULL && fast->next!=NULL){
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }

        prev->next=NULL;
        return slow;
    }

    ListNode* merge(ListNode* left, ListNode* right){
        ListNode* newHead=new ListNode(0);
        ListNode* temp=newHead;

        while(left!=NULL && right!=NULL){
            if(left->val<right->val){
                temp->next=left;
                temp=left;
                left=left->next;
            }
            else{
                temp->next=right;
                temp=right;
                right=right->next;
            }
        }

        while(left!=NULL){
            temp->next=left;
            temp=left;
            left=left->next;
        }

        while(right!=NULL){
            temp->next=right;
            temp=right;
            right=right->next;
        }

        return newHead->next;
    }

    ListNode* sortList(ListNode* head) {
        ios_base::sync_with_stdio(false);

        if(head==NULL || head->next==NULL){
            return head;
        }

        ListNode* mid=partition(head);
        ListNode* left=sortList(head);
        ListNode* right=sortList(mid);

        return merge(left, right);
    }
};

//----------------------------------------------------------------
/* 1. We will divide the list from the middle, to find the mid element we will use slow and fast pointer approach.
2. Then we will merge the left and right list using merge sort, where we will first take a dummy head as newHead.
3. The following nodes will be added by comparing the values in left and right list.
4. Finally return newHead->next. */
