class DisjointSet{
    public: 
    
    vector<int>par;
    vector<int>size;

    DisjointSet(int n){
        par.resize(n+1);
        size.resize(n+1,1);

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

        if(u == v) return;

        if(size[u] < size[v]){
            par[u] = v;
            size[v] += size[u];
        }
        else{
            par[v] = u;
            size[u] += size[v]; 
        }
    }
};

class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        DisjointSet d(n);
        
        for(auto it: edges){
            int u = it[0];
            int v = it[1];
            
            if(d.findpar(u) != d.findpar(v)){
                d.unionbysz(u,v);
            }
        }
        
        unordered_map<int,int>mp;
        
        for(int i=0;i<n;i++){
            mp[d.findpar(i)]++;
        }
        long long totalpairs = (long long)n*(n-1)/2;
        long long connectedpairs = 0;
        for(auto i: mp){
            connectedpairs +=  (long long)i.second*(i.second-1)/2;
        }
        
        return totalpairs-connectedpairs;
    }
};
