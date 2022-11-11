class Solution {
public:
    
    bool iscycle(int i,vector<int>&vis,vector<int>adj[],vector<int>&path){
        
            vis[i]=1;
            path[i]=1;
        
        for(auto it: adj[i]){
            
            if(!vis[it]){
                if(iscycle(it,vis,adj,path) == true){
                    return true;
                }
            }
            else if(path[it]){
                return true;
             }
        }        
        
        path[i] = 0;
        return false;
    }
    bool canFinish(int num, vector<vector<int>>& prerequisites) {
        
     
        vector<int>adj[num];
        vector<int>vis(num,0);
        vector<int>path(num,0);
        
        for(auto edge: prerequisites){
           adj[edge[0]].push_back(edge[1]);
        }
        
        for(int i=0;i<num;i++){
            if(!vis[i]){
                 if(iscycle(i,vis,adj,path)){
                    return false;
            }
            }
         
        }
        return true;
    }
};