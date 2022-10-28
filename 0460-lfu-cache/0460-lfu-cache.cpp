class LFUCache {

public:
    unordered_map<int, pair<int,int>>mp; // key -> {value,freq}
    unordered_map<int, list<int>>f;   //  freq -> list
    unordered_map<int, list<int>::iterator>address;  // key -> address in list
    int cap;
    int minfreq=0;
    
    LFUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        
        if(mp.find(key) == mp.end()) return -1;
        
        update(key);
        
        return mp[key].first;
    }
    
    void put(int key, int value) {
        
        if(cap <= 0) return;
        
        if(mp.find(key) != mp.end()){
            
            update(key);
            mp[key].first = value;
            
        }
        else{
            
            if(mp.size() >= cap){
                
                int k = f[minfreq].back();
                f[minfreq].pop_back();
                address.erase(k);
                mp.erase(k);
            }
                mp[key] = {value,0};
                f[0].push_front(key);
                address[key] = f[0].begin();

                minfreq=0;
        }

    }
    
    private:
    void update(int key){
        
        f[mp[key].second].erase(address[key]);
        mp[key].second++;
        f[mp[key].second].push_front(key);
        address.erase(key);
        address[key] = f[mp[key].second].begin();
        
        if(f[minfreq].size() == 0){
            minfreq++;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */