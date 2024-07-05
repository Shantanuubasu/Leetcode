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
    ListNode* reverse(ListNode* head){
        ListNode* temp=head;
        ListNode* prev=NULL;
        while(temp!=NULL){
            ListNode* front=temp->next;
            temp->next=prev;
            prev=temp;
            temp=front;
        }

        return prev;
    }
    ListNode* getkNode(ListNode* temp, int k){
        k-=1;
        while(temp!=NULL && k>0){
            temp=temp->next;
            k--;
        }

        return temp;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ios_base::sync_with_stdio(false);

        ListNode* temp=head;
        ListNode* prev=NULL;
        while(temp){
            ListNode* kNode=getkNode(temp, k);
            if(kNode==NULL){
                if(prev){
                    prev->next=temp;
                }
                break;
            }
            ListNode* nextNode=kNode->next;
            kNode->next=NULL;
            reverse(temp);
            if(head==temp){
                head=kNode;
            }
            else{
                prev->next=kNode;
            }

            prev=temp;
            temp=nextNode;
        }

        return head;
    }
};

//------------------------------------------------------------
/* 1. We will first find the kth node and reverse the whole list till kth node.
2. If head==temp then make head as kth node,else we will link the prev->next to kth node.
3. Finally, we will return head. */
