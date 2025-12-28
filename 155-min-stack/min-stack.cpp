class MinStack {
public:
stack<pair<int, int >> st;
int minval=INT_MAX;
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty()){
            minval=val;
            st.push({val,minval});
        }
        else{
            minval=min(minval, val);
            st.push({val, minval});
        }
    }
    
    void pop() {
        if(!st.empty()){
            auto &i=st.top();
            st.pop();
            if(!st.empty()){
            minval=st.top().second;
        }
        }
        
    }
    
    int top() {
        if(!st.empty()){
            return st.top().first;
        }
        return -1;
    }
    
    int getMin() {
        return minval;
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