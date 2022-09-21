class Solution {
public:

    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        
        if(n==1) return {0};
        vector<int>adj[n];
        vector<int>degree(n);
        
        for(auto edge: edges){
            
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
            
            degree[edge[0]]++;
            degree[edge[1]]++;
            
        }
        
        queue<int>q;
        
        for(int i=0;i<n;i++){
            if(degree[i]==1)
            q.push(i);
        }
       
        vector<int>ans;
        
        while(!q.empty()){
            
            ans.clear();
            
            int size = q.size();
            
            for(int i=0;i<size;i++){
                
                int node = q.front();
                q.pop();

                ans.push_back(node);
                
                
                for(auto it: adj[node]){
                    degree[it]--;
                    
                    if(degree[it]==1) q.push(it);
                }
            }
            
        }
        return ans;
    }
};