class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        
        int total = 0;
        
        int n = matrix.size();
        int m = matrix[0].size();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                
                if(matrix[i][j]==0){
                    continue;
                }
                
                if(i==0 || j==0){
                    total += matrix[i][j];
                    continue;
                }
                
  int sum=min(matrix[i-1][j],min(matrix[i-1][j-1],matrix[i][j-1]));
    
            matrix[i][j] += sum;
                
                total += matrix[i][j];
            }
        }
        return total;
    }
};