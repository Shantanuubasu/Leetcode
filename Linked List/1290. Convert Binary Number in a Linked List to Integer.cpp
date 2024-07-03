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
    int getDecimalValue(ListNode* head) {
        int num=0;
        while(head!=NULL){
            num=num<<1 | head->val;
            head=head->next;
        }

        return num;
    }
};

//-----------------------------------------------------------
/* 1. We will move num 1 bit towards left which is same as num*2 and then we will use or operator to add head->val to num.
2. Move head to next node.
3. Finally, return num. */
