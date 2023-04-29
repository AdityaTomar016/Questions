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
    
    int find_par(int u){
        if(par[u] == u){
            return u;
        }
        return par[u] = find_par(par[u]);
    }
    
    void unionbysz(int u,int v){
        u = find_par(u);
        v = find_par(v);
        
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
class comp1{
  public: 
    bool operator()(vector<int>&a,vector<int>&b){
        return a[2] < b[2];
    }
};

class Solution {
public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        
        DisjointSet d(n);
        
        for(int i=0;i<queries.size();i++){
            queries[i].push_back(i);
        }
        
        sort(queries.begin(),queries.end(),comp1());
        sort(edgeList.begin(),edgeList.end(),comp1());
        
        int i=0;
        vector<bool>ans(queries.size());
        
        for(auto q: queries){
            while(i<edgeList.size() && edgeList[i][2] < q[2]){
                d.unionbysz(edgeList[i][0],edgeList[i][1]);
                i++;
            }
            
            if(d.find_par(q[0]) == d.find_par(q[1])){
                ans[q[3]]= true;
            }
            else ans[q[3]] = false;
        }
        
        return ans;
    }
};