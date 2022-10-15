class Solution {
public:
    bool issafe(int row,int col,vector<string>ds,int n){
        
        int x = row;
        int y = col;
        
        
        while(x >= 0 && y >= 0){
            if(ds[x][y]=='Q'){
                return false;
            }
            x--;y--;
        }
        
        x = row,y=col;
        
        while(y>=0){
            if(ds[row][y]=='Q'){
                return false;
            }
            y--;
        }
        
        x = row,y=col;
        
        while(x < n && y >= 0){
            if(ds[x][y]=='Q'){
                return false;
            }
            x++;y--;
        }
        
        return true;
    }
    void solve(int col,int n,vector<string>&ds,vector<vector<string>>&ans){
        
        if(col==n){
            ans.push_back(ds);
            return;
        }
        
        for(int row=0;row<n;row++){
            if(issafe(row,col,ds,n)){
                ds[row][col]='Q';
                solve(col+1,n,ds,ans);
                ds[row][col]='.';
            }
        }
        
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string>ds;
        vector<vector<string>>ans;
        
        string s(n,'.');
        
        for(int i=0;i<n;i++){
            ds.push_back(s);
        }
        
        solve(0,n,ds,ans);
        
        return ans;
    }
};