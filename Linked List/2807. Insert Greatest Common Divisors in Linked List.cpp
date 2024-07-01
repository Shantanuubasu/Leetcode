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
    int calculateGcd(int a, int b){
        return b==0 ? a : calculateGcd(b, a%b);
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ios_base::sync_with_stdio(false);

        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* back=head;
        ListNode* front=head->next;

        while(front!=NULL){
            ListNode* n=new ListNode(calculateGcd(back->val, front->val));
            back->next=n;
            n->next=front;
            back=front;
            front=front->next;
        } 

        return head;
    }
};

//---------------------------------------------------------------------------------------
/* 1. We define a function to calculate gcd of two numbers.
2. If head or head->next is null then return head.
3. We take two pointers back and front, we calculate gcd of back and front and insert a node with gcd as value between them.
4. Then we move back and front to the next nodes.
5. Finally, return head. */
