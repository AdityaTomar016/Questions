class Solution {
public:
  bool color(int i ,int c,vector<int>&vis,vector<int>&col,vector<int>adj[]){

        col[i]=c;      
        vis[i]=1;
        
        for(auto it: adj[i]){
          if(!vis[it]){
            if(!color(it,c^1,vis,col,adj)) return false;
           }
            else{
                if(col[i]==col[it])
                    return false;
            }
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        
        vector<int>adj[n+1];
        
        for(auto edge: dislikes){
           adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        vector<int>vis(n+1,0);
        vector<int>col(n+1,-1);
        
  
        
        for(int i=0;i<n;i++){
            if(!vis[i] && !color(i,0,vis,col,adj)) return false;
        }
        return true;
    }
};