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

        ListNode* newHead=reverse(head->next);
        ListNode* front=head->next;
        front->next=head;
        head->next=NULL;

        return newHead;
    }

    int pairSum(ListNode* head) {
        ios_base::sync_with_stdio(false);

        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }

        ListNode* newHead=reverse(slow->next);
        ListNode* temp1=head;
        ListNode* temp2=newHead;
        int maxi=0;
        while(temp2!=NULL){
            int sum=temp1->val+temp2->val;
            maxi=max(maxi,sum);
            temp1=temp1->next;
            temp2=temp2->next;
        }

        return maxi;
    }
};

//--------------------------------------------------------------------------
/* 1. We will reverse the list from half way point.
2. Now we will traverse in both the first and second half of the list.
3. Update maxi value according to the maximum sum.
4. Finally, return sum. */
