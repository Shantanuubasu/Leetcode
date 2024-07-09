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
    ListNode* removeElements(ListNode* head, int val) {
        ios_base::sync_with_stdio(false);

        if(head==NULL){
            return head;
        }

        ListNode* temp=head;
        ListNode* dummy=new ListNode(-1);
        dummy->next=head;
        ListNode* prev=dummy;
        while(temp!=NULL){
            if(temp->val==val){
                prev->next=temp->next;
                temp=prev->next;
            }
            else{
                prev=temp;
                if(temp){
                    temp=temp->next;
                }
            }
        }

        return dummy->next;
    }
};

//---------------------------------------------------------------
/* 1. We add a dummy node in before head, point to head.
2. Now we traverse in the list, prev will point to the node before the temp node. temp will start from head.
3. If temp's value is same as val then we point the prev->next to temp->next.
4. Finally, return dummy->next. */
