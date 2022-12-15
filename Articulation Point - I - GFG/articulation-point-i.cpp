//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  int timer=0;
  
  void dfs(int node,int parent,vector<int>&vis,vector<int>&time,vector<int>&low,vector<int>adj[],vector<int>&ans){
      vis[node] = 1;
      time[node] = low[node] = timer;
      timer++;
      int child = 0;
      
      for(auto it: adj[node]){
          if(it == parent) continue;
          if(!vis[it]){
              dfs(it,node,vis,time,low,adj,ans);
              
              low[node] = min(low[node], low[it]);
              
              if(low[it] >= time[node] && parent != -1){
                  ans[node] = 1;
              }
              child++;
              
          }
          else{
              low[node] = min(low[node], time[it]);
          }
      }
      if(child > 1 && parent == -1){
          ans[node] = 1;
      }
  }
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        // Code here
        
        vector<int>time(V);
        vector<int>low(V);
        vector<int>vis(V,0);
        vector<int>ans(V,0);
        
        for(int i=0;i<V;i++){
            if(!vis[i])
            dfs(i,-1,vis,time,low,adj,ans);
        }
        
        vector<int>res;
        
        for(int i=0;i<V;i++){
            if(ans[i] == 1){
                res.push_back(i);
            }
        }
        
        if(res.size() == 0) return {-1};
        
        return res;
    }
};

//{ Driver Code Starts.

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends