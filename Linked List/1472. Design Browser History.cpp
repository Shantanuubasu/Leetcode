inline const auto optimize = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return 0;
}();

class BrowserHistory {
    struct Node{
        string url;
        struct Node *next, *prev;
    };
public:
    Node* head;
    BrowserHistory(string homepage) {
        head=new Node();
        head->url=homepage;
        head->next=NULL;
        head->prev=NULL;
    }
    
    void visit(string url) {
        Node* n=new Node();
        n->url=url;
        n->next=head;
        n->prev=NULL;
        head->prev=n;
        head=n;
    }
    
    string back(int steps) {
        while(head->next!=NULL && steps>0){
            head=head->next;
            steps--;
        }

        return head->url;
    }
    
    string forward(int steps) {
        while(head->prev!=NULL && steps>0){
            head=head->prev;
            steps--;
        }

        return head->url;
        
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */

//---------------------------------------------------------------------------------
/* 1. Define a structure node to create nodes with value as url and pointers as next and prev.
2. Now in the BrowserHistory(), we will initalize a new node with value as url and next and prev pointers as NULL.
3. In visit(), create a new node and assign this new node as previous of head and update head as new node.
4. In back(), We travel back in the browser history so we move towards head->next, steps number of times and finally return head->url.
5. In forward(), we travel forward in the browser history so we move towards head->prev, steps number of times and finally return head->url. */
