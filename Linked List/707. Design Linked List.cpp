class Node{
    public:
        int val;
        Node* next;
        Node(int v){
            this->val=v;
            this->next=NULL;
        }
};

class MyLinkedList {
public:
    Node* head;
    MyLinkedList() {
        head=NULL;        
    }
    
    int get(int index) {
        Node* temp=head;
        while(index>0 && temp!=NULL){
            temp=temp->next;
            index--;
        }

        if(temp==NULL){
            return -1;
        }

        return temp->val;
    }
    
    void addAtHead(int val) {
        Node* n=new Node(val);
        if(head==NULL){
            head=n;
        }
        else{
            n->next=head;
            head=n;
        }
    }
    
    void addAtTail(int val) {
        Node* n=new Node(val);
        if(head==NULL){
            head=n;
        }
        else{
            Node* temp=head;
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=n;
        }
    }
    
    void addAtIndex(int index, int val) {
        Node* n=new Node(val);
        Node* temp=head;
        if(index==0){
            n->next=head;
            head=n;
        }
        else{
            while(temp!=NULL && index>1){
                temp=temp->next;
                index--;
            }
            if(temp==NULL){
                return;
            }
            else if(temp!=NULL && temp->next==NULL){
                temp->next=n;
            }
            else{
                n->next=temp->next;
                temp->next=n;
            }
        }
    }
    
    void deleteAtIndex(int index) {
        Node* temp=head;
        if(index==0){
            head=head->next;
        }
        else{
            while(temp!=NULL && index>1){
                temp=temp->next;
                index--;
            }
            if(temp==NULL){
                return;
            }
            if(temp!=NULL && temp->next==NULL){
                temp->next=NULL;
            }
            else{
                temp->next=temp->next->next;
            }
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */

//---------------------------------------------------------------------------------------
/* 1. We will first define a Node class with a constructor to create Node objects.
2. In the MyLinkedList(), we will initialize the linked list head as NULL.
3. In get() we will traverse to the required node using a temp node and if temp is NULL then we return -1, otherwise, we return temp->val.
4. In addAtHead(), we will first create a Node object with value as val and if head is NULL then n will be the only node so assign n to head, else we will make n->next as head and update head to n.
5. In addAtTail(), we will check if the head is NULL then the only node will be n then assign it to head, else, we will traverse till the node whose next is NULL and then assign n to it.
6. In addAtIndex(), if the index is 0 that means we need to insert at head then we will add node to head, else, we will traverse to the node before the index we need to add and then we will add the node there.
7. In deleteAtIndex(), if index is 0 then we need to delete head so we move head to next, else we will traverse to the node before the one we have to delete and then break the link to the next node and assign to next->next. */
