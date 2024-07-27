
class MyQueue {
private:
    stack<int> s1;
    stack<int> s2;

public:
    MyQueue() {}

    void push(int x) {
        s1.push(x);
    }

    int pop() {
        if(s2.empty()==false){
            int t=s2.top();
            s2.pop();
            return t;
        }
        else{
            while(s1.empty()==false){
                s2.push(s1.top());
                s1.pop();
            }

            int t=s2.top();
            s2.pop();
            return t;
        }
    }

    int peek() {
        if(s2.empty()){
            while(s1.empty()==false){
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();
    }

    bool empty() {
        return (s1.empty() && s2.empty());
    }
};

//------------------------------------------------------------
/* 1. We will take two stacks.
2. For push we will push to s1 stack.
3. For pop if s2 is not empty then pop its top elements, otherwise, move all the numbers from s1 to s2 and then pop the top from s2.
4. In peek, if s2 is empty then move all elements from s1 to s2 and then return top of s2.
5. In empty. return if both are empty or not. */
