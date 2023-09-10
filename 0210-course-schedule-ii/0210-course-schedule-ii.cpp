class Solution {
public:
    bool isCycle(int i,vector<int>&vis,vector<int>&pathvis,vector<int>&res,vector<int>adj[]){
        
        vis[i] = 1;
        pathvis[i] = 1;
        
        for(auto it: adj[i]){
            if(!vis[it]){
                if(isCycle(it,vis,pathvis,res,adj)){
                    return true;
                }
            }
            else if(pathvis[it] == 1){
                return true;
            }
        }
        
        res.push_back(i);
        pathvis[i] = 0;
        
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<int>adj[numCourses];
        
        for(auto it: prerequisites){
            adj[it[0]].push_back(it[1]);    
        }
        
        vector<int>res;
        
        vector<int>vis(numCourses,0);
        vector<int>pathvis(numCourses,0);
        
        for(int i=0;i<numCourses;i++){
            if(!vis[i] && isCycle(i,vis,pathvis,res,adj)){
                return {};
            }
        }
        
        return res;
    }
};