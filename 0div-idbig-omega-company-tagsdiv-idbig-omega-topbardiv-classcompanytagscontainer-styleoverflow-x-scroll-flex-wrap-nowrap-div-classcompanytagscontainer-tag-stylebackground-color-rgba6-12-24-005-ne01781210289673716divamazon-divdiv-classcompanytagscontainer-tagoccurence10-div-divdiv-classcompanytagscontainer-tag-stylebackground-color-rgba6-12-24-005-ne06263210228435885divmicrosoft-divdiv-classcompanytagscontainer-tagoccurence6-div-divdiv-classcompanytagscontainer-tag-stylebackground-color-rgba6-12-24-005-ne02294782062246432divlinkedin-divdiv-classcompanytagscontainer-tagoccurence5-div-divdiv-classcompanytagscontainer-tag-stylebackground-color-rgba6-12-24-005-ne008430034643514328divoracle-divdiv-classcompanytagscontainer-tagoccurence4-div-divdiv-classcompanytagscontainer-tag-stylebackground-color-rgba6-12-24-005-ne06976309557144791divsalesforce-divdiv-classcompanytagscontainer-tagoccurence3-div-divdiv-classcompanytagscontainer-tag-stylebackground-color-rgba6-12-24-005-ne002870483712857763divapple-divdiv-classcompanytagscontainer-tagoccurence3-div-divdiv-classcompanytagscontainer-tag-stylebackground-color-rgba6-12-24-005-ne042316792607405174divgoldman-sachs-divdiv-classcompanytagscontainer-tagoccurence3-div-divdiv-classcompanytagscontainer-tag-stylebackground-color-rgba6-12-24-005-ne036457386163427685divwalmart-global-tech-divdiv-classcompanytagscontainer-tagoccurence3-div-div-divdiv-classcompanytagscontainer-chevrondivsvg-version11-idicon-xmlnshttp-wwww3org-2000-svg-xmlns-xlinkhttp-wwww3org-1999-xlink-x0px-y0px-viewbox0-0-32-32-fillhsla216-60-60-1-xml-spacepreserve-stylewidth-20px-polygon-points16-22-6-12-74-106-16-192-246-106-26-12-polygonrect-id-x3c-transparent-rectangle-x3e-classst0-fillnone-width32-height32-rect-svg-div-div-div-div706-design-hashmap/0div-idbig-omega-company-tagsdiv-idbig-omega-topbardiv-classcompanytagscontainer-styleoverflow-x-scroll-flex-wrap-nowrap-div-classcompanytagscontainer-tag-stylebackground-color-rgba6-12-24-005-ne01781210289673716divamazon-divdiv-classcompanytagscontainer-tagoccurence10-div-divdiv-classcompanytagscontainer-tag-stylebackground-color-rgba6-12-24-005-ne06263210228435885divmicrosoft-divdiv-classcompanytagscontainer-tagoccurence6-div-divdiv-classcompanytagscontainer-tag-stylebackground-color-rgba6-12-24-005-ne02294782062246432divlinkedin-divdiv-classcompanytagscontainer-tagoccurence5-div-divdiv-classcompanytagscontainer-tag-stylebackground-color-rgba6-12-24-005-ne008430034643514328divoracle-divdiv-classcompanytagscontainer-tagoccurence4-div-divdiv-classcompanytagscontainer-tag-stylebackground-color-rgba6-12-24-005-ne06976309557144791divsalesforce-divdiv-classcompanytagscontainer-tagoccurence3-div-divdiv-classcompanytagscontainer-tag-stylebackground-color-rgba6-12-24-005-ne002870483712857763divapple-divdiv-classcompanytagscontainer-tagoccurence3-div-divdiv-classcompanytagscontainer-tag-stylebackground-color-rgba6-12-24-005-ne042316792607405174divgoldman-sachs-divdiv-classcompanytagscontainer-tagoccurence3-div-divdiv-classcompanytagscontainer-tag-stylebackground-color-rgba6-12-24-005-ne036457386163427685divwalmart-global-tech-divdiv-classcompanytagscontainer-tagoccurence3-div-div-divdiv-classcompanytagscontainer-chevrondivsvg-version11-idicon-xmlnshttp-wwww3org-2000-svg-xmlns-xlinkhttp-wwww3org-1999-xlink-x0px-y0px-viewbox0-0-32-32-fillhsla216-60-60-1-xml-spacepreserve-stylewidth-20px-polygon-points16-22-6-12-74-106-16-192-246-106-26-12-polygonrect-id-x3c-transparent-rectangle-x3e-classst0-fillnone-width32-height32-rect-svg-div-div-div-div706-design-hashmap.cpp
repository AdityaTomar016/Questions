class MyHashMap {
public:
    vector<list<pair<int,int>>>mp;
    int sz;
    
    MyHashMap() {
        sz = 1e6;
        mp.resize(sz);
    }
    
    void put(int key, int value) {
        int i = key%sz;
        
        for(auto &it: mp[i]){
            if(it.first == key){
                it.second = value;
                return;
            }
        }
        mp[i].push_back({key,value});
    }
    
    int get(int key) {
        int i = key%sz;
        
        for(auto &it: mp[i]){
            if(it.first == key){
                return it.second;
            }
        }
        
        return -1;
    }
    
    void remove(int key) {
        int i = key%sz;
        
        for(auto &it: mp[i]){
            if(it.first == key){
                mp[i].remove(it);
                return;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */