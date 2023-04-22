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
        if(u == par[u]){
            return u;
        }
        
        return par[u] = findpar(par[u]);
    }
    
    void uninonbysz(int u,int v){
        u = par[u];
        v = par[v];
        
        if(u == v){
            return;
        }
        
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
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
        DisjointSet d(10001);
        vector<int>ans(2);
        
        for(auto i: edges){
            int u = i[0];
            int v = i[1];
            
            if(d.findpar(u) == d.findpar(v)){
                ans[0] = u;
                ans[1] = v;
            }
            else{
                d.uninonbysz(u,v);
            }
        }
        
        return ans;
    }
};