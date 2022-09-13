class MinStack {
public:
    stack<long long>st;
    long long mini;
    
    MinStack() {
        while(!st.empty()) st.pop();
        mini = INT_MAX;
    }
    
    void push(int value) {
        
        long long val = value;
        
        if(st.empty()){
            st.push(val);
            mini = val;
        }
        else if(val < mini){
            st.push(2*val*1LL - mini);
            mini = val;
        }
        else {
            st.push(val);
        }
    }
    
    void pop() {
        
        if(st.empty()) return;
        
        long long x = st.top();
        st.pop();
        
        if(x < mini){
            mini = (2*mini - x);
        }
        
    }
    
    int top() {
        if(st.empty()) return -1;
        
        long long x = st.top();
        
        if(x < mini){
           return mini;
        }
        else return x;
    }
    
    int getMin() {
        return mini;
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