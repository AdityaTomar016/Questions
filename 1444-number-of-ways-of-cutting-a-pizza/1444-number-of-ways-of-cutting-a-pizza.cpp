class Solution {
public:
    long long MOD = 1000000007;
    bool hasApple(vector<string>& grid, int startRow, int endRow, int startCol, int endCol) {
        for (int i = startRow; i <= endRow; i++) {
            for (int j = startCol; j <= endCol; j++) {
                if (grid[i][j] == 'A') 
                    return true;
            }
        }
        return false;
    }
    int waysToCutPizza(vector<string>& grid, vector<vector<vector<int>>>& dp, int startRow, int startCol, int cutsLeft) {
        int numRows = grid.size();
        int numCols = grid[0].size();
        if (cutsLeft == 0) 
            return 1;
        if (dp[startRow][startCol][cutsLeft] != -1) 
            return dp[startRow][startCol][cutsLeft];
        long long ans = 0;
        //make a cut below the row with index 'row'
        for (int row = startRow; row < numRows - 1; row++) {
            bool upperHalfHasApple = hasApple(grid, startRow, row, startCol, numCols - 1);
            bool lowerHalfHasApple = hasApple(grid, row + 1, numRows - 1, startCol, numCols - 1);
            //give away upper half
            if (upperHalfHasApple && lowerHalfHasApple) {
                int nextWays = waysToCutPizza(grid, dp, row + 1, startCol, cutsLeft - 1); //cut lower half
                ans = (ans + nextWays) % MOD;
            }
        }
        //make a cut to the right of column with index 'col'
        for (int col = startCol; col < numCols - 1; col++) {
            bool leftHalfHasApple = hasApple(grid, startRow, numRows - 1, startCol, col); 
            bool rightHalfHasApple = hasApple(grid, startRow, numRows - 1, col + 1, numCols - 1);
            //give away left half 
            if (leftHalfHasApple && rightHalfHasApple) {
                int nextWays = waysToCutPizza(grid, dp, startRow, col + 1, cutsLeft - 1); //cut right half
                ans = (ans + nextWays) % MOD;
            }
        }
        return dp[startRow][startCol][cutsLeft] = (int)ans;
    }
    int ways(vector<string>& grid, int k)
    {
        int numRows = grid.size(), numCols = grid[0].size();
        vector<vector<vector<int>>> dp(numRows, vector<vector<int>>(numCols, vector<int>(k, -1)));
        int ans = waysToCutPizza(grid, dp, 0, 0, k - 1);
        return ans;    
    }
};