class LRUCache {
public:
    unordered_map<int,int>mp;
    list<int>l;
    unordered_map<int,list<int>::iterator>address;
    int cap;
    int siz=0;
    
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        
        if(mp.find(key)==mp.end()) return -1;
        
        l.erase(address[key]);
        l.push_front(key);
        address.erase(key);
        address[key] = l.begin();
            
            
        return mp[key];
    }
    
    void put(int key, int value) {
        
        if(mp.find(key)!=mp.end()){
            l.erase(address[key]);
            address.erase(key);
            mp.erase(key);
            siz--;
        }
        
        if(siz == cap){
            int k = l.back();
            l.pop_back();
            address.erase(k);
            mp.erase(k);
            siz--;
        }
        mp[key] = value;
        l.push_front(key);
        address[key] = l.begin();
        siz++;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */