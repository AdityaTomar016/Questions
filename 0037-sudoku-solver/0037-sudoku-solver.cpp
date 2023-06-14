class Solution {
public:
    bool isSafe(char ch,int row,int col,vector<vector<char>> &board){
        
        for(int i=0;i<9;i++){
            if(board[i][col] == ch){
                return false;
            }
        }
        for(int i=0;i<9;i++){
            if(board[row][i] == ch){
                return false;
            }
        }
        
        row = row - row%3;
        col = col - col%3;
        
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(board[row+i][col+j] == ch){
                    return false;
                }
            }
        }
        
        return true;
    }
    bool solve(vector<vector<char>>& board){
        
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                
                if(board[i][j]=='.'){
                    
                    for(char c='1';c<='9';c++){
                        
                        if(isSafe(c,i,j,board)){
                            board[i][j]=c;
                            
                            if(solve(board))
                                return true;
      
                            else board[i][j]='.';

                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};