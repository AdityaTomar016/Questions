class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        int ans = 0;
        int r=0,c=m-1;
        
        while(r < n){
            while(c >= 0 && grid[r][c] < 0) c--;
            ans += m-c-1;
            r++;
        }
        
        return ans;
    }
};