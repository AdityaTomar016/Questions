class Solution {
public:
    bool solve(int i,int j,int k,vector<vector<char>>& board, string word){
        
        if(k == word.size()){
            return true;
        }
        
        if(i >= board.size() || i < 0 || j >= board[0].size() || j<0){
            return false;
        }
        
        if(board[i][j] != word[k]){
            return false;
        }
        
        char ch = board[i][j];
        board[i][j] = '#';
        bool flag = false;
        
        flag = solve(i+1,j,k+1,board,word) ||                              solve(i-1,j,k+1,board,word) ||
               solve(i,j+1,k+1,board,word) ||
               solve(i,j-1,k+1,board,word);
        
        board[i][j] = ch;
        
        return flag;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int k = 0;
        
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(solve(i,j,0,board,word)){
                    return true;
                }
            }
        }
        return false;
    }
};