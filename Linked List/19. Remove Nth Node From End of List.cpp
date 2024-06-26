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
//----------------------------------------------------------------------------------------------------

// APPROACH - 2 - COUNT NODES

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
        int count=0; 
        ListNode* temp=head;

        while(temp!=NULL){
            ++count;
            temp=temp->next;
        }

        int prevnode=count-n-1;
        temp=head;

        if(prevnode==-1){
            ListNode* newhead=head->next;
            delete head;
            return newhead;
        }

        while(prevnode!=0){
            temp=temp->next;
            prevnode--;
        }

        ListNode* del=temp->next;
        temp->next=temp->next->next;
        delete del;

        return head;
    }
};

//----------------------------------------------------------------------
/* To remove the desired node from the list we will do the following steps.

1. First we count the number of nodes in the linked list.
2. Now we will find the node which comes before the node we have to remove.
3. Then we will check if the we have to remove the head, if yes, then we will simply delete the head and return the next node.
4. If we don't have to remove the node then we will traverse the list to reach the previous node of the node that has to be deleted and point that node to the next of next of that node.
5. Finally we will delete the desired node and return the head. */
