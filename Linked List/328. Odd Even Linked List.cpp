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
    ListNode* oddEvenList(ListNode* head) {
        ios_base::sync_with_stdio(false);

        if(head==NULL || head->next==NULL || head->next->next==NULL){
            return head;
        }
        ListNode* evenHead=head->next;
        ListNode* ptr1=head;
        ListNode* ptr2=evenHead;
        while(ptr1!=NULL && ptr2!=NULL && ptr2->next!=NULL){
            ptr1->next=ptr2->next;
            ptr1=ptr1->next;
            ptr2->next=ptr1->next;
            ptr2=ptr2->next;
        }
        ptr1->next=evenHead;

        return head;
        
    }
};

//--------------------------------------------------------------------------------
/* 1. If we have linked list with 2 or lesser nodes then no change is needed, return head.
2. We will divide the list into two sub list - odd and even.
3. For even we take a evenHead which will point to 2nd node.
4. ptr1 pointer is for odd list and ptr2 for even list.
5. Update ptr1->next to point to next odd element which is ptr2->next and move the ptr1 pointer ahead.
6. Now do the same for ptr2 pointer and move it ahead.
7. Finally we will have two list, as we need to arrange in odd followed by even then we will point the tail of odd list to evenHead.
8. Finally, return head. */
