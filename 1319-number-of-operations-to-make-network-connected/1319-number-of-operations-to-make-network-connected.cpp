class DisjointSet{
    public:
    vector<int>sz,par;
    
    DisjointSet(int n){
        sz.resize(n+1,1);
        par.resize(n+1);
        
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
    
    void unionbysz(int u,int v){
        u = findpar(u);
        v = findpar(v);
        
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
    int makeConnected(int n, vector<vector<int>>& con) {
        DisjointSet d(n);
        int extra = 0;
        
        for(auto i: con){
            int u = i[0];
            int v = i[1];
            
            if(d.findpar(u) == d.findpar(v)){
                extra++;
            }
            else
            d.unionbysz(u,v);
        }
        
        int com=0;
        
        for(int i=0;i<n;i++){
            if(d.par[i] == i){
                com++;
            }
        }
        
        if(extra >= com-1){
            return com-1;
        }
        
        return -1;
    }
};