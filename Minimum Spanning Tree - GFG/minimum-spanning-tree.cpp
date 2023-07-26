//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class DisjointSet{
  public:
  vector<int>par,rank;
  
  DisjointSet(int n){
      par.resize(n+1);
      rank.resize(n+1,0);
      
      for(int i=0;i<=n;i++){
          par[i] = i;
      }
  }
  int find_par(int u){
      if(u == par[u]){
          return par[u];
      }
      return par[u] = find_par(par[u]);
  }
  
  void unionbyrank(int u,int v){
      u = find_par(u);
      v = find_par(v);
      
      if(u == v) return;
      else if(rank[u] < rank[v]){
          par[u] = v;
      }
      else if(rank[v] < rank[u]){
          par[v] = u;
      }
      else{
          par[v] = u;
          rank[u]++;
      }
  }
  
};
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<pair<int,pair<int,int>>>edges;
        for(int i=0;i<V;i++){
            for(auto it: adj[i]){
                int u = i;
                int v = it[0];
                int wt = it[1];
                
                edges.push_back({wt,{u,v}});
            }
        }
        
        sort(edges.begin(),edges.end());
        
        DisjointSet ds(V);
        int sum=0;
        
        for(auto i: edges){
            int u = i.second.first;
            int v = i.second.second;
            int wt = i.first;
            
            if(ds.find_par(u) != ds.find_par(v)){
                ds.unionbyrank(u,v);
                sum += wt;
            }
        }
        
        return sum;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends