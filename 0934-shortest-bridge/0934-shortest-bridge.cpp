class Solution {
public:
    vector<int>dx = {-1,0,1,0};
    vector<int>dy = {0,-1,0,1};
    
    queue<pair<int,int>>q;
    bool isValid(int i,int j,int n,int m,vector<vector<int>>&grid){
        if(i<0 || j<0 || i>=n || j>=m || grid[i][j] == 2){
            return false;
        }
        return true;
    }
    int bfs(int n,int m,vector<vector<int>>&grid){
        int mini = INT_MAX;
        int dis = 0;
        
        while(!q.empty()){
            int sz = q.size();
            
            while(sz--){
                int x = q.front().first;
                int y = q.front().second;
                
                q.pop();
                
                for(int i=0;i<4;i++){
                    int row = x + dx[i];
                    int col = y + dy[i]; 
                    
                    if(isValid(row,col,n,m,grid)){
                        if(grid[row][col] == 1){
                            mini = min(mini,dis);
                        }
                        else{
                             q.push({row,col});
                            grid[row][col] = 2;
                        }
                    }
                }
            }
            
            dis++;
        }
        return mini;
    }
    void dfs(int i,int j,int n,int m,vector<vector<int>>&grid){
        if(i<0 || j<0 || i>=n || j>=m || grid[i][j] != 1){
            return;
        }
        grid[i][j] = 2;
        q.push({i,j});
        
        for(int it=0;it<4;it++){
            int row = i + dx[it];
            int col = j + dy[it];
            
            dfs(row,col,n,m,grid);
        }
    }
    int shortestBridge(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        
        bool flag = false;
        
        for (int i=0; i<grid.size(); i++){
            for (int j=0; j<grid[0].size(); j++){
                if (grid[i][j] == 1){ 
                    dfs(i,j,n,m,grid);
                    flag = true;
                    break;
                }
            }
            
            if(flag) break;
        }
        return bfs(n,m,grid);
    }
};