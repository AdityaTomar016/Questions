//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    
    bool check(int src,vector<int> &vis,vector<int> adj[]){
        vis[src] = 1;
        queue<pair<int,int>>q;
        q.push({src,-1});
        
        while(!q.empty()){
            int src = q.front().first;
            int par = q.front().second;
            
            q.pop();
            
            for(auto i: adj[src]){
                if(!vis[i]){
                    vis[i]=1;
                    q.push({i,src});
                }
                else if(i != par){
                    return true;
                }
            }
            
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        
         vector<int>vis(V+1,0);
         
        for(int i=0;i<V;i++){
            
            if(!vis[i]){
                if(check(i,vis,adj)){
                    return true;
                }
            }
        }
        return false;
       
        
        
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends