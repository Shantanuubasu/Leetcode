// APPROACH - 1 - ONE PASS

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ios_base::sync_with_stdio(false);

        ListNode* slow=head;
        ListNode* fast=head;

        for(int i=0; i<n; i++){
            fast=fast->next;
        }

        if(fast==NULL){
            return head->next;
        }

        while(fast->next!=NULL){
            slow=slow->next;
            fast=fast->next;
        }

        slow->next=slow->next->next;

        return head;
    }
};

//-----------------------------------------------------------
/* 1. We will take two pointer slow and fast, move fast ahead n places.
2. If fast is NULL then that means we have to remove head, so we return head->next.
3. Now we will move both pointers together at same speed until fast reaches the last node.
4. Now the slow pointer will point to the node previous to the one that needs to be deleted.
5. Now we delete the required node.
6. Finally, return head. */
