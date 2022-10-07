class MyCalendarThree {
public:
    map<int,int>mp;
    
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        
        mp[start]++;
        mp[end]--;
        
        int booking=0,k=0;
        
        for(auto it: mp){
            
            booking += it.second;
            k = max(k,booking);
        }
        return k;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */