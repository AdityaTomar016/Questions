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

    bool unionbysz(int u,int v){
        u = findpar(u);
        v = findpar(v);

        if(u == v) return false;

        if(size[u] < size[v]){
            par[u] = v;
            size[v] += size[u];
        }
        else{
            par[v] = u;
            size[u] += size[v]; 
        }
        
        return true;
    }
};
class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        
        DisjointSet d_alice(n);
        DisjointSet d_bob(n);
        
        sort(edges.begin(),edges.end(),[&](auto const &a, auto const &b){
            return a[0] > b[0];
        });
        int a_edges=0,b_edges=0,extra = 0;
        
        int i=0;
        for(auto e: edges){
            if(e[0] == 3){
                if(d_alice.unionbysz(e[1],e[2])){
                    d_bob.unionbysz(e[1],e[2]);
                    a_edges++;
                    b_edges++;
                }
                else extra++;
            }
            else if(e[0] == 2){
                if(d_alice.unionbysz(e[1],e[2])){
                    a_edges++;
                }
                 else extra++;
            }
            else{
                 if(d_bob.unionbysz(e[1],e[2])){
                    b_edges++;
                }
                 else extra++;
            }
        }
        
        if(a_edges == n-1 && b_edges == n-1){
            return extra;
        }
        
        return -1;
    }
};