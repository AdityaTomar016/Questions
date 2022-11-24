class Solution {
public:
    bool solve(int i,int j,int k,string word,vector<vector<char>>& board){
        
        if(k == word.size()){
            return true;
        }
        
        if(i<0 || j<0 || i>=board.size() || j>=board[0].size() || word[k]!=board[i][j]){
            return false;
        }
        
        char c = board[i][j];
        board[i][j] = '.';
        
        if (solve(i+1,j,k+1,word,board) ||                              solve(i-1,j,k+1,word,board) ||                              solve(i,j+1,k+1,word,board) ||                              solve(i,j-1,k+1,word,board)){
            return true;
        }
        
        board[i][j] = c;
        
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(solve(i,j,0,word,board))
                    return true;
            }
        }
        
        return false;
    }
};