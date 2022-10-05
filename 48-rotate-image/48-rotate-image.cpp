class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        int m = matrix[0].size();
        
        for(int i=0;i<n;i++){
            for(int j=i;j<m;j++){
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
        
        int i=0;
        while(n--){
            reverse(matrix[i].begin(),matrix[i].end());
            i++;
        }
    }
};