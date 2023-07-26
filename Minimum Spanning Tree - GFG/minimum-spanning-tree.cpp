//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        
        // vector<pair<int,int>> adj[V+1];
        
        // for(int i=0;i<V;i++){
        //     for(auto it: edge[i]){
        //         int u = it[0];
        //         int v = it[1];
        //         int wt = it[2];
                
        //         adj[u].push_back({v,wt});
        //         adj[v].push_back({u,wt});
        //     }
        // }
        
        vector<int>vis(V+1,0);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,0});
        
        int sum=0;
        
        while(!pq.empty()){
            auto x = pq.top();
            pq.pop();
            
            int node = x.second;
            int wt = x.first;
            
            if(vis[node] == 1) continue;
            
            vis[node] = 1;
            sum += wt;
            
            for(auto it: adj[node]){
                int v = it[0];
                int dis = it[1];
                
                if(!vis[v]){
                    pq.push({dis,v});
                }
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