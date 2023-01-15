class DisjointSet{
    public: 
    
    vector<int>par;
    vector<int>rank;
    int count;

    DisjointSet(int n){
        par.resize(n+1);
        rank.resize(n+1,0);

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
    bool connected(int u,int v){
        return par[u] == par[v];
    }
    
    void unionbyrank(int u,int v){
        u = findpar(u);
        v = findpar(v);

        if(u == v) return;

        if(rank[u] < rank[v]){
            par[u] = v;
        }
        else{
            par[v] = u;
            if(rank[u] == rank[v]) rank[v]++;
        }
        // --n;
    }
};
class Solution {
public:
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n = vals.size();
        int ans = 0;
        
        vector<int>adj[n];
        map<int,vector<int>> mp;
        
        for(int i=0;i<n;i++){
            mp[vals[i]].push_back(i);
        }
        
        for(auto it: edges){
            int u = it[0];
            int v = it[1];
            
            if(vals[u] >= vals[v]){
                adj[u].push_back(v);
            }
            else if(vals[v] >= vals[u]){
                adj[v].push_back(u);
            }
        }
        
        DisjointSet d(n);
        
        for(auto it: mp){
            int val = it.first;
            auto nodes = it.second;
            
            for(auto u: nodes){
                for(auto v: adj[u]){
                    d.unionbyrank(u,v);
                }
            }
            
            unordered_map<int,int> group;
            
            for(auto i: nodes){
                group[d.findpar(i)]++;
            }
            
            ans += nodes.size();
            
            for(auto i: group){
                int sz = i.second;
                ans += (sz * (sz-1) / 2);
            }
        }
        
        return ans;
    }
};