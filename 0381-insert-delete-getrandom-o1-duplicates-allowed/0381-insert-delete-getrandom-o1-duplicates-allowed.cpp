class RandomizedCollection {
public:
    unordered_map<int,set<int>>mp;
    vector<int>v;
    
    RandomizedCollection() {
     
    }
    
    bool insert(int val) {
        v.push_back(val);
        mp[val].insert(v.size()-1);
        
        return mp[val].size()==1;
    }
    
    bool remove(int val) {
        auto it = mp.find(val);
        
        if(it != mp.end()){
            int pos = *it->second.begin();
            it->second.erase(it->second.begin());
            v[pos] = v.back();
            mp[v.back()].insert(pos);
            mp[v.back()].erase(v.size()-1);
            v.pop_back();
            
            if(it->second.size() == 0){
                mp.erase(it);
            }
            
            return true;
        }
        return false;
    }
    
    int getRandom() {
        return v[rand()%v.size()];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */