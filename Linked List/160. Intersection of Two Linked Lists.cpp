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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ios_base::sync_with_stdio(false);

        ListNode* temp1=headA;
        ListNode* temp2=headB;

        while(temp1!=temp2){
            temp1= temp1==NULL ? headB : temp1->next;
            temp2= temp2==NULL ? headA : temp2->next;
        }

        return temp1;
    }
};

//--------------------------------------------------------------------------------------
/* 1. We will take two pointer for list A and B.
2. If any pointer becomes NULL at any point we will assign it to the head of the other list.
3. After few iteration we will find the intersection node.
4. Finally, return temp1. */
