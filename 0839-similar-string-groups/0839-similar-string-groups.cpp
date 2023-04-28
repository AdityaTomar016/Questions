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
    
    bool similar(string a,string b){
        int cnt = 0;
        
        for(int i=0;i<a.size();i++){
            if(a[i] != b[i]){
                cnt++;
            }
        }
        
        return (cnt == 2 || cnt == 0);
    }
    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        
        DisjointSet d(n);
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(similar(strs[i],strs[j])){
                    d.unionbysz(i,j);
                }
            }
        }
        
        int groups = 0;
        for(int i=0;i<n;i++){
            if(d.par[i] == i){
                groups++;
            }
        }
        
        return groups;
    }
};