class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        for(int i=0;i<n;i++){
            int l = 0,r = m-1;
            
            if(target >= matrix[i][l] && target <= matrix[i][r]){
                while(l<=r){
                    int mid = (l+r)/2;
                    
                    if(l == r && matrix[i][l] != target) break;
                    if(matrix[i][mid] == target){
                        return true;
                    }
                    else if(target > matrix[i][mid]){
                        l = mid+1;
                    }
                    else {
                        r = mid;
                    }
                }
            }
        }
        return false;
    }
};