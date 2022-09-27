class Solution {
public:
    void dfs(int i,int j,int n,vector<vector<int>>&mat){
        
        if(i<0 || i>=n || j<0 || j>=n || mat[i][j]==0){
            return;
        }
        
        mat[i][j]=0;
        
        dfs(i,j+1,n,mat);
        dfs(i,j-1,n,mat);
        dfs(i+1,j,n,mat);
        dfs(i-1,j,n,mat);
    }
    int regionsBySlashes(vector<string>& grid) {
        
        int n = grid.size();
        int N = n*3;
        vector<vector<int>>mat(N,vector<int>(N,1));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                
           if(grid[i][j] == '/'){
                  mat[i*3][j*3+2]=0;
                  mat[i*3+1][j*3+1]=0;
                  mat[i*3+2][j*3]=0;
              }
              
            else if(grid[i][j] == '\\'){
                  mat[i*3][j*3]=0;
                  mat[i*3+1][j*3+1]=0;
                  mat[i*3+2][j*3+2]=0;
              }
        }
        }
              
              
      int count=0;
        
      for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(mat[i][j]){
                    count++;
                    dfs(i,j,N,mat);
                }
            }
      }
              
      return count;
              
    }
};