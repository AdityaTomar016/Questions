class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row_st=0,col_st=0,row_end = matrix.size()-1,col_end = matrix[0].size()-1;
        vector<int>ans;
        
        while(row_st<=row_end && col_st <= col_end){
            for(int i=col_st;i<=col_end;i++){
                ans.push_back(matrix[row_st][i]);
            }
            row_st++;
            
            for(int i=row_st;i<=row_end;i++){
                ans.push_back(matrix[i][col_end]);
            }
            
            col_end--;
            
            if(row_st > row_end || col_st > col_end){
                break;
            }
            
            for(int i=col_end;i>=col_st;i--){
                ans.push_back(matrix[row_end][i]);
            }
            row_end--;
            
            for(int i=row_end;i>=row_st;i--){
                ans.push_back(matrix[i][col_st]);
            }
            col_st++;
        }
        
        return ans;
    }
};