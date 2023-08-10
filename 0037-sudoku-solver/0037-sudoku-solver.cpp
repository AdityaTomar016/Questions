class Solution {
public:
    bool issafe(int row,int col,char ch,vector<vector<char>>& board){
        for(int i=0;i<9;i++){
            if(board[i][col] == ch){
                return false;
            }
        }
        for(int j=0;j<9;j++){
            if(board[row][j] == ch){
                return false;
            }
        }
        row = row-row%3;
        col = col-col%3;
        
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
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j] == '.'){
                    for(char ch='1';ch<='9';ch++){
                        if(issafe(i,j,ch,board)){
                            
                            board[i][j] = ch;
                            
                            if(solve(board)){
                                return true;
                            }
                            else{
                                board[i][j] = '.';   
                            }   
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