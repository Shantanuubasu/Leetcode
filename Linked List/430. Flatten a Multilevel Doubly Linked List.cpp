/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        ios_base::sync_with_stdio(false);

        Node* temp=head;
        while(temp){
            Node* front=temp->next;
            if(temp->child!=NULL){
                Node* child=temp->child;
                temp->child=NULL;
                child=flatten(child);
                temp->next=child;
                child->prev=temp;
                while(child->next!=NULL){
                    child=child->next;
                }
                child->next=front;
                if(front!=NULL){
                    front->prev=child;
                }
            }
            temp=front;
        }

        return head;
    }
};

//-----------------------------------------------------------------
/* 1. Assign temp as head and iterate till temp is not null.
2. If temp's child is not null then store child in a variable and point temp->child as NULL. Also, take next node as front.
3. Now call flatten() with child as parameter.
4. Make temp->next as child and child->prev as temp.
5. Now iterate to the last node of child list and assign child->next as front.
6. Check if front is not null if not then assign front->prev as child.
7. Finally, return head. */
