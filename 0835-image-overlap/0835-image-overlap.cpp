class Solution {
public:
    
    int overlap(int x,int y,vector<vector<int>>& img1, vector<vector<int>>& img2){
        int res=0;
        
        for(int i=0;i<img1.size();i++){
            for(int j=0;j<img1[0].size();j++){
                
                if((i+x < 0 || i+x >= img1.size()) || (j+y < 0 || j+y >= img1[0].size()))
                    continue;
                    
                if(img1[i][j] + img2[i+x][j+y] == 2){
                    res++;
                }
            }
        }
        return res;
    }
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int ans=0;
        int n = img1.size();
        int m = img1[0].size();
        
        for(int i=-n+1;i<n;i++){
            for(int j=-m+1;j<m;j++){
                ans = max(ans,overlap(i,j,img1,img2));
            }
        }
        
        return ans;
    }
};