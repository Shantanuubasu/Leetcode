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
    ListNode* doubleIt(ListNode* head) {
        ios_base::sync_with_stdio(false);

        ListNode* revhead=reverse(head);

        int carry=0;
        ListNode* curr=revhead;
        ListNode* prev=nullptr;

        while(curr!=nullptr){
            int num=curr->val*2+carry;
            curr->val=num%10;
            if(num>9){
                carry=1;
            }
            else{
                carry=0;
            }

            prev=curr;
            curr=curr->next;
        }

        if(carry>0){
            ListNode* newnode=new ListNode(carry);
            prev->next=newnode;
        }

        ListNode* newhead=reverse(revhead);

        return newhead;
    }
};

//-----------------------------------------------------------------
/* 1. We will first reverse the list.
2. We will traverse in the reversed list and keep on doubling the node value and also adding carry.
3. If the value updated is greater than 9 then carry will be 1, else 0.
4. At last if we have carry greater than 0 then we will add a new node the list.
5. Finally reverse the list again and return the head. */
