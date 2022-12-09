//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
    
    // void solve(int i,int j,int n,int m,int N,int steps,int &ans,vector<vector<int>>&vis){
    //     if(i<0 || j<0 || i>=N || j>=N || vis[i][j] == 1){
    //         return;
    //     }
    //     if(i==n && j==m){
    //         ans = min(ans,steps);
    //     }
        
    //     vis[i][j] = 1;
        
    //     solve(i+2,j-1,n,m,N,steps+1,ans,vis);
    //     solve(i+2,j+1,n,m,N,steps+1,ans,vis);
    //     solve(i-2,j-1,n,m,N,steps+1,ans,vis);
    //     solve(i-2,j+1,n,m,N,steps+1,ans,vis);
    //     solve(i+1,j+2,n,m,N,steps+1,ans,vis);
    //     solve(i+1,j-2,n,m,N,steps+1,ans,vis);
    //     solve(i-1,j-2,n,m,N,steps+1,ans,vis);
    //     solve(i-1,j+2,n,m,N,steps+1,ans,vis);
        
    //     vis[i][j] = 0;
        
    // }
    
    bool isValid(int i,int j,int N){
          if(i<0 || j<0 || i>=N || j>=N){
            return false;
         }
         
         return true;
    }
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    
	    vector<vector<int>>vis(N+1,vector<int>(N+1,0));
	    
	    int steps=0;
	    int ans=INT_MAX;
	    
	    vector<pair<int,int>>dir={ {-1,2},{-1,-2},{-2,-1},{-2,1},{2,-1},{2,1},{1,-2},{1,2} };

	    int n = TargetPos[0];
	    int m = TargetPos[1];
	    
	    int i = KnightPos[0];
	    int j = KnightPos[1];
	    
	    if(i==n && j==m){
	        return 0;
	    }
	    
	    queue<vector<int>>q;
	    q.push({i,j,0});
	    
	    while(!q.empty()){
	        auto x = q.front();
	        q.pop();
	        
	        int row = x[0];
	        int col = x[1];
	        int steps = x[2];
	        
	        for(auto it: dir){
	            int newr = row + it.first;
	            int newc = col + it.second;
	            
	            if(newr == n && newc == m){
	                return steps+1;
	            }
	            if(isValid(newr,newc,N) && vis[newr][newc]==0){
	                q.push({newr,newc,steps+1});
	                vis[newr][newc] = 1;
	            }
	        }
	    }

	    return -1;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends