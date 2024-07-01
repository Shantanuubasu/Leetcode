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
    ListNode* rotateRight(ListNode* head, int k) {
        ios_base::sync_with_stdio(false);

        if(head==NULL || head->next==NULL){
            return head;
        }
        int nodes=1;
        ListNode* temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
            nodes++;
        }
        temp->next=head;
        int rotations=k%nodes;

        int i=0;
        temp=head;
        int it= (nodes>k) ? nodes-k-1 : nodes-rotations-1;
        while(i<it){
            temp=temp->next;
            i++;
        }
        head=temp->next;
        temp->next=NULL;

        return head;


    }
};

//-------------------------------------------------------------------------
/* 1. If head or head->next is NULL then return head.
2. Now we will count nodes in the list, also calculate the number of rotations we would need by doing k%nodes.
3. Now make the list a circular linked list by pointing the end node to head.
4. If nodes>k then take iterator as nodes-k-1, otherwise take it as nodes-rotations-1.
5. Now iterate in list for iterator times and break the link and assign the next node as head.
6. Finally, return head. */
