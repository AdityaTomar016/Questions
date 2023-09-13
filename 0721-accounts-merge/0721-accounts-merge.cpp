class DisjointSet{
  public: 
    vector<int>par,sz;
    
    DisjointSet(int n){
        par.resize(n+1);
        sz.resize(n+1,1);
        
        for(int i=0;i<=n;i++){
            par[i] = i;
        }
    }
    int findpar(int u){
        if(u == par[u]) return u;
        
        return par[u] = findpar(par[u]);
    }
    void unionbysz(int u,int v){
        u = findpar(u);
        v = findpar(v);
        
        if(u == v) return;
        
        if(sz[u] > sz[v]){
            par[v] = u;
            sz[u] += sz[v];
        }
        else{
            par[u] = v;
            sz[v] += sz[u];
        }
    }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        
        unordered_map<string,int>mp;
        int n = accounts.size();
        
        DisjointSet ds(n);
        
        for(int i=0;i<n;i++){
            vector<string> ac = accounts[i];
            for(int j=1;j<ac.size();j++){
                
                string email = ac[j];
                
                if(mp.find(email) != mp.end()){
                    ds.unionbysz(i,mp[email]);
                }
                else{
                    mp[email] = i;
                }
            }
        }
        vector<string>adj[n];
        
        for(auto i: mp){
            int node = i.second;
            string email = i.first;
            
            int parent = ds.findpar(node);
            adj[parent].push_back(email);
        }
        
        vector<vector<string>>res;
        
        for(int i=0;i<n;i++){
            
            if(adj[i].size() == 0) continue;
            sort(adj[i].begin(),adj[i].end());
            
            vector<string>temp;
            temp.push_back(accounts[i][0]);
            
            for(auto it: adj[i]){
                temp.push_back(it);
            }
            
            res.push_back(temp);
        }
        
        return res;
    }
};