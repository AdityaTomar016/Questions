//{ Driver Code Starts
#include <bits/stdc++.h>
#include<stdio.h>
#include<math.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long solve(int i,int prev,int preprev,int n,int k,vector<vector<vector<int>>>&dp){
        if(i == n){
            return 1;
        }
        
        if(dp[i][prev+1][preprev+1] != -1){
            return dp[i][prev][preprev];
        }
        
        long long count=0;
        for(int col=1;col<=k;col++){
            if(prev == col && preprev == col){
                continue;
            }
            
            count += solve(i+1,col,prev,n,k,dp);
        }
        
        return dp[i][prev+1][preprev+1] = count;
    }
    
    long long mod = 1e9+7;
    
    long long countWays(int n, int k){
        if(n == 0){
            return 0;
        }
        
        if(n == 1){
            return k;
        }
        
        long long same = k%mod;
        long long diff = (k*(k-1))%mod;
        
        for(int i=3;i<=n;i++){
            long long prevdiff = diff%mod;
            
            diff = ((same+diff)*(k-1))%mod;
            same = (prevdiff*1)%mod;
        }
        
        return (same+diff)%mod;
    }
};

//{ Driver Code Starts.

int main()
{
	
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		Solution ob;
		cout<<ob.countWays(n,k)<<endl;
	}
	return 0;
}
// } Driver Code Ends