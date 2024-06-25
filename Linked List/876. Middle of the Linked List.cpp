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
    ListNode* middleNode(ListNode* head) {
        ios_base::sync_with_stdio(false);
        
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL && fast->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;
    }
};

//-------------------------------------------------------------------------
/* 1. To solve this problem we will use two pointer approach, we define pointers slow and fast, slow will cover one node at a time and fast will cover two nodes at a time. So, by the end of the list fast will reach end and slow will reach middle of the list.
2. Inside the while loop we make the pointers move accordingly and finally return the slow pointer. */
