class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> ans(n,vector<int>(m,INT_MAX));
        queue<pair<int,pair<int,int>>>q;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j] == 0){
                    q.push({0,{i,j}});
                }
            }
        }
        
        vector<int>dx = {0,1,0,-1};
        vector<int>dy = {-1,0,1,0};
        
        
        while(!q.empty()){
            auto x = q.front();
            q.pop();
            int dis = x.first;
            int i = x.second.first;
            int j = x.second.second;
            
            mat[i][j] = 2;
            ans[i][j] = min(ans[i][j],dis);
            
            for(int it=0;it<4;it++){
                int x = i+dx[it];
                int y = j+dy[it];
                
                if(x>=0 && y>=0 && x<n && y<m && mat[x][y] == 1){
                    q.push({dis+1,{x,y}});
                }
            }
        }
        return ans;
    }
};