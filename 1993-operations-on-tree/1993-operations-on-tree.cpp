class LockingTree {
public:
    unordered_map<int,vector<int>>desc;
    vector<vector<int>>Nodes;
    
    LockingTree(vector<int>& parent) {
        int n = parent.size();
        Nodes.resize(n,vector<int>(2,-1));
        
        for(int i=0;i<n;i++){
            Nodes[i][0] = parent[i];
            desc[parent[i]].push_back(i);
        }
    }
    
    bool lock(int num, int user) {
        if(Nodes[num][1] != -1){
            return false;
        }
        
        Nodes[num][1] = user;
        return true;
    }
    
    bool unlock(int num, int user) {
        if(Nodes[num][1] != user){
            return false;
        }
        
        Nodes[num][1] = -1;
        return true;
    }
    
    bool upgrade(int num, int user) {
        if(Nodes[num][1] != -1){
            return false;
        }
        
        if(!anyDescLocked(num)){
            return false;
        }
        
        if(anyAncLocked(Nodes[num][0])){
            return false;
        }
        
        Unlockdesc(num);
        Nodes[num][1] = user;
        return true;
    }
    
    bool anyDescLocked(int num){
        if(desc.count(num) == 0 || desc[num].size() == 0) return false;
        
        for(auto i: desc[num]){
            if(Nodes[i][1] != -1){
                return true;
            }
            
            if(anyDescLocked(i)) return true;
        }
        
        return false;
    }
    bool anyAncLocked(int num){
       if(num  == -1) return false;
        
        return Nodes[num][1] != -1 || anyAncLocked(Nodes[num][0]);
    }
    void Unlockdesc(int num){
        if(desc.count(num) == 0 || desc[num].size() == 0) return;
        
        for(auto i: desc[num]){
            Nodes[i][1] = -1;
            Unlockdesc(i);
        }
    }
};

/**
 * Your LockingTree object will be instantiated and called as such:
 * LockingTree* obj = new LockingTree(parent);
 * bool param_1 = obj->lock(num,user);
 * bool param_2 = obj->unlock(num,user);
 * bool param_3 = obj->upgrade(num,user);
 */