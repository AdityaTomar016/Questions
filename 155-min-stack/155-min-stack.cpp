class MinStack {
public:
    
    int v[100000];
    int topelement;
    
    MinStack() {
        topelement = -1;
    }
    
    void push(int val) {
        if(topelement == -1){
            topelement++;
            v[topelement] = val;
            topelement++;
            v[topelement] = val;
        }
        else{
            int x = min(v[topelement], val);
            
            topelement++;
            v[topelement] = val;
            topelement++;
            v[topelement] = x;
        }
    }
    
    void pop() {
        topelement-=2;
    }
    
    int top() {
        return v[topelement-1];
    }
    
    int getMin() {
        return v[topelement];
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