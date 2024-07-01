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
    ListNode* mergeNodes(ListNode* head) {
        ios_base::sync_with_stdio(false);

        int sum=0;
        ListNode* back=head;
        while(back!=NULL && back->next!=NULL){
            ListNode* front=back->next;
            while(front->val!=0){
                sum+=front->val;
                front=front->next;
            }
            front->val=sum;
            back->next=front;
            sum=0;
            back=front;
        }

        head=head->next;

        return head;
    }
};

//----------------------------------------------------------
/* 1. Take two pointer one points at first 0, other to the next 0.
2. Move front till it reaches a node with value 0, and keep adding the values of nodes in between.
3. Now make the value of front node as sum and point back to front and make sum 0.
4. Move head to next node.
5. Finally, return head. */
