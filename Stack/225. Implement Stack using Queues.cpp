class MyStack {
public:
    queue<int> q;
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
        for(int i=0; i<q.size()-1; i++){
            int t=q.front();
            q.pop();
            q.push(t);
        }
    }
    
    int pop() {
        int t=q.front();
        q.pop();

        return t;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        if(q.size()==0){
            return true;
        }

        return false;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

//----------------------------------------------------------------------------
/* 1. We will take a queue, for the push to work as in stack we will first push the current element and then
   we will pop elements pushed before it and then push them again one by one.
2. For pop, we can simple return q.front value and pop it.
3. For top, we will return q.front.
4. For empty, we check if q's size is 0, if yes then return true. Otherwise, return false. */
