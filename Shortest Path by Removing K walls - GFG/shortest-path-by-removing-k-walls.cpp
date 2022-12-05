//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:

    int shotestPath(vector<vector<int>> mat, int n, int m, int k) {
        
        vector<int>dx = {-1,0,1,0};
        vector<int>dy = {0,1,0,-1};
        
        vector<vector<int>>vis(n,vector<int>(m,-1));
        
        queue<vector<int>>q;
        q.push({0,0,0,k});
        
        while(!q.empty()){
            auto x = q.front();
            q.pop();
            
            int i = x[0];
            int j = x[1];
            
            if(i<0 || i>=n || j<0 || j>=m){
              continue;
            }
            
            if(i == n-1 && j == m-1){
                return x[2];
            }
            
            if(mat[i][j] == 1){
                if(x[3] > 0){
                    x[3]--;
                }
                else continue;
            }
            
            if(vis[i][j] != -1 && vis[i][j] >= x[3]){
                continue;
            }
            
            vis[i][j] = x[3];
            
            
            for(int it=0;it<4;it++){
                q.push({i+dx[it],j+dy[it],x[2]+1,x[3]});
            }
        }
        
        return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, k, x;
        
        cin>>n>>m>>k;
        vector<vector<int>> mat;
    
        for(int i=0; i<n; i++)
        {
            vector<int> row;
            for(int j=0; j<m; j++)
            {
                cin>>x;
                row.push_back(x);
            }
            mat.push_back(row);
        }

        Solution ob;
        cout<<ob.shotestPath(mat,n,m,k);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends