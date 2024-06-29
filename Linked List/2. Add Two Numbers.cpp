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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ios_base::sync_with_stdio(false);

        ListNode* temp=new ListNode(0);
        ListNode* end=temp;
        int carry=0;

        while(l1!=nullptr || l2!=nullptr || carry!=0){
            int d1=(l1!=nullptr) ? l1->val:0;
            int d2=(l2!=nullptr) ? l2->val:0;
            int sum=d1+d2+carry;
            int d=sum%10;
            carry=sum/10;
            ListNode* newNode=new ListNode(d);
            end->next=newNode;
            end=end->next;
            l1=(l1!=nullptr) ? l1->next:nullptr;
            l2=(l2!=nullptr) ? l2->next:nullptr;
        }
        ListNode* r=temp->next;
        delete temp;
        return r;
    }
};

//---------------------------------------------------------------------
/* 1. Take a dummy node as head of a new list.
2. Now we will add every corresponding node and update the carry.
3. We will make a new node for each sum.
4. We will continue this till we reach end of both the list and carry is 0.
5. Finally, remove the dummy node and return head. */
