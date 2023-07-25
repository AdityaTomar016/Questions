class Solution {
public:
    void dfs(int i,int j,int col,int color,vector<vector<int>>& image){
        if(i>=image.size() || i<0 || j>=image[0].size() || j<0){
            return;
        }
        if(image[i][j] != col || image[i][j] == color){
            return;
        }
        
        image[i][j] = color;
        
        dfs(i+1,j,col,color,image);
        dfs(i-1,j,col,color,image);
        dfs(i,j+1,col,color,image);
        dfs(i,j-1,col,color,image);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int col = image[sr][sc];
        dfs(sr,sc,col,color,image);
        return image;
    }
};