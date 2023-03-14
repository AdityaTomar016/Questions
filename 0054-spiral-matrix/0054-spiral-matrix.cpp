class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        vector<int>ans;
        
        int rowst = 0,colst = 0, rowend = n-1, colend = m-1;
        
        while(rowst <= rowend && colst <= colend){
            
            for(int i=colst;i<=colend;i++){
                ans.push_back(matrix[rowst][i]);
            }
            rowst++;
            for(int i=rowst;i<=rowend;i++){
                ans.push_back(matrix[i][colend]);
            }
            colend--;
            
            if(rowst > rowend || colst > colend){
                break;
            }
            
            for(int i=colend;i>=colst;i--){
                ans.push_back(matrix[rowend][i]);
            }
            rowend--;
            for(int i=rowend;i>=rowst;i--){
                ans.push_back(matrix[i][colst]);
            }
            colst++;
            
        }
        
        return ans;
        
    }
};