class Solution {
public:
    vector<int>dx = {-1,0,1,0};
    vector<int>dy = {0,1,0,-1};
    
    bool isValid(int i,int j,int n){
        if(i<0 || j<0 || i>=n || j>=n) return false;
        return true;
    }
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        
        vector<vector<int>>vis(n,vector<int>(n,0));
        
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        
        pq.push({grid[0][0],{0,0}});
        vis[0][0] = 1;
        
        while(!pq.empty()){
            auto t = pq.top();
            pq.pop();
            
            int dis = t.first;
            int i = t.second.first;
            int j = t.second.second;
            
            if(i == n-1 && j == n-1){
                return dis;
            }
            
            for(int it=0;it<4;it++){
                int x = i + dx[it];
                int y = j + dy[it];
                
                if(isValid(x,y,n) && vis[x][y] == 0){
                    int nextdis = max(dis,grid[x][y]);
                    pq.push({nextdis,{x,y}});
                    vis[x][y] = 1;
                }
            }
        }
        
        return -1;
    }
};