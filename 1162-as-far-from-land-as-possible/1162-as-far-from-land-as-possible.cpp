class Solution {
public:

bool isValid(int i,int j,int n){
    if(i<0 || j<0 || i>=n || j>=n){
        return false;
    }

    return true;
}
    int maxDistance(vector<vector<int>>& grid) {
        
        int n = grid.size();
        queue<pair<int,int>>q;

        vector<int>dx = {-1,0,1,0};
        vector<int>dy = {0,-1,0,1};

        vector<vector<int>> vis(n,vector<int>(n,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1){
                    q.push({i,j});
                    vis[i][j] = 1;
                }
            }
        }
        int dist = 0;
        int ans = INT_MIN;
        while(!q.empty()){
            int sz = q.size();

            while(sz--){
                auto x = q.front();
                q.pop();
                int i = x.first;
                int j = x.second;

                for(int it=0;it<4;it++){
                    int row = i + dx[it];
                    int col = j + dy[it];

                    if(isValid(row,col,n) && vis[row][col] == 0 && grid[row][col] == 0){
                        vis[row][col] = 1;
                        q.push({row,col});
                    }
                }
                
            }
            ans = max(ans,dist);
            dist++;
        }
        if(ans == INT_MIN || ans == 0){
            return -1;
        }
        return ans;
    }
};