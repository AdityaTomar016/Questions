class MyCircularQueue {
public:
    
    vector<int>q;
    int sz,cnt,head;
    
    MyCircularQueue(int k) {
        
        q.resize(k);
        
        sz=k;
        
        cnt=0;
        
        head=0;
    }
    
    bool enQueue(int value) {
        
        if(isFull()) return false;
        
        q[(head + cnt) % sz] = value;
        cnt++;
        
        return true;
    }
    
    bool deQueue() {
        
        if(isEmpty()) return false;
        
        head = (head + 1) % sz;
        cnt--;
        
        return true;
    }
    
    int Front() {
        
        if(isEmpty()) return -1;
        
        return q[head];
    }
    
    int Rear() {
        
        if(isEmpty()) return -1;
        
        return q[(head + cnt - 1) % sz];
    }
    
    bool isEmpty() {
        
        if(cnt == 0) return true;
        
        return false;
    }
    
    bool isFull() {
        
        if(cnt == sz) return true;
        
        return false;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */