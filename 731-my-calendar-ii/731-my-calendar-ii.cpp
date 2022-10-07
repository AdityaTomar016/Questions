class MyCalendarTwo {
public:
    
    map<int,int>mp;
    
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        mp[start]++;
        mp[end]--;
        
        int booking=0;
        
        for(auto it: mp){
            
            booking += it.second;
            
            if(booking >= 3){
                mp[start]--;
                mp[end]++;
                
                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */