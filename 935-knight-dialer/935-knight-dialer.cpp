class Solution {
public:
    int mod = 1e9+7;
   
long paths(vector<vector<vector<long>>> &M, int i, int j, int n) {
   
   if(i < 0 || j < 0 || i >= 4 || j >= 3 || (i == 3 && j != 1)) return 0;
   if(n == 1) return 1;
   
   if(M[n][i][j] > 0) return M[n][i][j];

   M[n][i][j] = paths(M, i - 1, j - 2, n - 1) % mod +
                paths(M, i - 2, j - 1, n - 1) % mod +
                paths(M, i - 2, j + 1, n - 1) % mod +
                paths(M, i - 1, j + 2, n - 1) % mod +
                paths(M, i + 1, j + 2, n - 1) % mod +
                paths(M, i + 2, j + 1, n - 1) % mod +
                paths(M, i + 2, j - 1, n - 1) % mod +
                paths(M, i + 1, j - 2, n - 1) % mod; 
   return M[n][i][j];
}
               
    
    int knightDialer(int n) {
vector<vector<vector<long>>>M(n+1,vector<vector<long>>(4,vector<long>(3,0)));
        
        long long s = 0;
        
        for(int i=0;i<4;i++){
            for(int j=0;j<3;j++){
                s = (s + paths(M,i,j,n)) % mod;
            }
        }
        
        return s;
    }
};