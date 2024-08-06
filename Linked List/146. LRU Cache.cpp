class LRUCache {
public:
    class Node{
        public:
        int key;
        int val;
        Node *next;
        Node *prev;
        Node(int k, int v){
            key=k;
            val=v;
        }
    };

    unordered_map<int, Node*> mp;
    Node* head= new Node(-1, -1);
    Node* tail= new Node(-1, -1);
    int cap;

    void insertAfterHead(Node* n){
        Node* temp=head->next;
        n->next=temp;
        n->prev=head;
        head->next=n;
        temp->prev=n;
    }

    void deleteNode(Node* n){
        Node* delprev=n->prev;
        Node* delnext=n->next;
        delprev->next=delnext;
        delnext->prev=delprev;
    }

    LRUCache(int capacity) {
        head->next=tail;
        tail->prev=head;
        cap=capacity;
    }
    
    int get(int key) {
        if(mp.find(key)!=mp.end()){
            Node* temp=mp[key];
            int val=temp->val;
            mp.erase(key);
            deleteNode(temp);
            insertAfterHead(temp);
            mp[key]=head->next;
            return val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            Node* temp=mp[key];
            mp.erase(key);
            deleteNode(temp);
        }
        if(mp.size()==cap){
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }

        Node* n=new Node(key, value);
        insertAfterHead(n);
        mp[key]=head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

//----------------------------------------------------------------------------------
/* 1. We will use doubly linked list and map to implement LRU cache.
2. In LRUCache(), initialize head next to point to tail, tail previous to point head and cap as capacity.
3. In get(), if the key is found in the map, we retrieve its corresponding node and erase the key from map. Delete the node and insert it after the head as it is recently accessed and add this node to map and return node's value.
4. If not found in the map then return -1.
5. In put(), we find the key in map, if found then we erase it from the map and delete the node.
6. If size of map becomes equal to cap, erase the node before the tail and delete it too.
7. Then make a new node with given key and value, insert it after the head and also add it to the map. */
