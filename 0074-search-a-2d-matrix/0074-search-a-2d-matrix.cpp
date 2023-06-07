class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        int low = 0,high = m-1;
        
        while(low < n && high >= 0){
            int curr = matrix[low][high];
            
            if(curr == target) return true;
            
            if(target > curr) low++;
            else high--;
        }
        
        return false;
    }
};