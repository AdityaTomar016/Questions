class Solution {
public:
    void dfs(int node,vector<int>&vis,vector<int>&dist,vector<int>&edges){
        
        vis[node] = 1;
        int next = edges[node];
        
        if(next != -1 && !vis[next]){
            dist[next] = 1 + dist[node];
            dfs(next,vis,dist,edges);
        }
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) { 
        int n = edges.size();
        vector<int>dist1(n,1e9),dist2(n,1e9);
        vector<int>vis1(n,0),vis2(n,0);
        
        dist1[node1] = 0;
        dist2[node2] = 0;
        
        dfs(node1,vis1,dist1,edges);
        dfs(node2,vis2,dist2,edges);
        
        int ansNode = -1;
        int mindis = 1e9;
        
        for(int i=0;i<n;i++){
            
            if(mindis > max(dist1[i],dist2[i])){
                ansNode = i;
                mindis = max(dist1[i],dist2[i]);   
            }
        }
        
        return ansNode;
    }
};