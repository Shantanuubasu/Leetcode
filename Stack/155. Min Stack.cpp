class MinStack {
public:
    stack<pair<int, int >> st;
    MinStack() {
        ios_base::sync_with_stdio(false);

    }
    
    void push(int val) {
        if(st.empty() || val<=st.top().second){
            st.push({val, val});
        }
        else{
            st.push({val, st.top().second});
        }

    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

//------------------------------------------------------------------------------------
/* 1. We will stack with pair of val and current minimum value.
2. In push(), we check if stack is empty or val is less than current minimum then we push val in both places.
3. Else, we push val and current min.
4. In pop(), we simply pop.
5. In top(), we return top.first.
6. in getMin(), we return top.second. */
