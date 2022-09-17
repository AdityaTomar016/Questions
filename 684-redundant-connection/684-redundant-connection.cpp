class Solution {
public:
//     const 
    vector<int>parent;
    vector<int>size;
    
    void make_sets(int i){
        parent[i]=i;
        size[i]=1;
    }
    
    int find_sets(int v){
        if(v==parent[v]){
            return v;
        }
        
        return parent[v] = find_sets(parent[v]);
    }
    
    void union_sets(int a,int b){
        a = find_sets(a);
        b = find_sets(b);
        
        if(a!=b){
            if(size[a] < size[b]){
                swap(a,b);
            }
            parent[b]=a;
            size[a]+=size[b];
        }
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
            
        int n = edges.size();
        
        int N = 1e5+6;
        parent.resize(N);
        size.resize(N);
        
        vector<int>ans;
        
        for(int i=0;i<N;i++){
            make_sets(i);
        }
        
        for(auto i: edges){
            int u = i[0];
            int v = i[1];
            
            int x = find_sets(u);
            int y = find_sets(v);
            
            if(x==y){
                ans.push_back(u);
                ans.push_back(v);
                break;
            }
            else {
                union_sets(u,v);
            }
        }
        return ans;
    }
};