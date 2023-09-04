//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    vector<pair<int,int>>dir = {{-1,2},{-1,-2},{-2,-1},{-2,1},{2,-1},{2,1},{1,-2},{1,2}};
	    vector<vector<int>>vis(N+1,vector<int>(N+1,0));
	    
	    queue<pair<int,int>>q;
	    q.push({KnightPos[0],KnightPos[1]});
	    vis[KnightPos[0]][KnightPos[1]] = 1;
	    
	    int steps=0;
	    
	    while(!q.empty()){
	        int sz=q.size();
	        while(sz--){
	            int i = q.front().first;
	            int j = q.front().second;
	            q.pop();
	            
	            if(i == TargetPos[0] && j == TargetPos[1]){
	                return steps;
	            }
	            
	            for(auto dr: dir){
	                int x = i + dr.first;
	                int y = j + dr.second;
	                
	                if(x>=1 && y>=1 && x<=N && y<=N && !vis[x][y]){
	                    q.push({x,y});
	                    vis[x][y] = 1;
	                }
	                
	            }
	        }
	        steps++;
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