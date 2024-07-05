/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        ios_base::sync_with_stdio(false);

        Node* temp=head;
        while(temp!=NULL){
            Node* n=new Node(temp->val);
            Node* nxt=temp->next;
            n->next=nxt;
            temp->next=n;
            temp=nxt;
        }

        temp=head;
        while(temp!=NULL){
            Node* copy=temp->next;
            if(temp->random){
                copy->random=temp->random->next;
            }
            else{
                copy->random=NULL;
            }
            temp=temp->next->next;
        }

        Node* dummy=new Node(-1);
        Node* ans=dummy;
        temp=head;
        while(temp!=NULL){
            ans->next=temp->next;
            ans=ans->next;
            temp->next=ans->next;
            temp=temp->next;
        }

        return dummy->next;
    }
};

//---------------------------------------------------------
/* 1. First we will create the copy of the nodes next to it.
2. Then we will point the random pointers of all the copy nodes according to its original nodes.
3. Then we will take a dummy node as head of this copy list and then we will make next pointers point to the correct nodes.
4. Finally, we will return dummy->next. */
