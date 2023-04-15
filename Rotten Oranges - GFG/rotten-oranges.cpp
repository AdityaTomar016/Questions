//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int ans = 0;
    vector<int>dx={0,-1,0,1};
    vector<int>dy={1,0,-1,0};
    
    void bfs(int i,int j,int n,int m,vector<vector<int>>& grid){
        queue<pair<int,int>>q;
        q.push({i,j});
        
        int dis = -1;
        
        while(!q.empty()){
            auto t = q.front();
            q.pop();
            
            int x = t.first;
            int y = t.second;
            
            if(grid[x][y] == 2){
                dis = abs(i-x) + abs(j-y);
                ans = max(ans,dis);
                return;
            }  
            
            for(int it=0;it<4;it++){
                int r = x + dx[it];
                int c = y + dy[it];
                
                if(r>=0 && c>=0 && r<n && c<m && grid[r][c] != 0){
                    q.push({r,c});
                }
            }
        }
        if(dis == -1){
            ans = -1;
            return;
        }
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1)
                bfs(i,j,n,m,grid);
                
                if(ans == -1){
                    return -1;
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends