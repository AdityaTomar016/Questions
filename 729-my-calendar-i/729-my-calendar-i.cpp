class MyCalendar {
public:
    map<int,int>mp;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        
        mp[start]++;
        mp[end]--;
        
        int booking=0;
        
        for(auto it: mp){
            
            booking += it.second;
            
            if(booking >= 2){
                mp[start]--;
                mp[end]++;
                
                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */