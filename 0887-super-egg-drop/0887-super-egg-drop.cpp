class Solution {
public:
    int solve(int e,int f,vector<vector<int>> &dp){
        if(f == 0 || f == 1){
            return f;
        }
        if(e == 1){
            return f;
        }
        if(dp[e][f] != -1){
            return dp[e][f];
        }
        
        int mini = INT_MAX;
        
        for(int k=1;k<=f;k++){
            int temp = 1 + max(solve(e-1,k-1,dp), solve(e,f-k,dp));
            
            mini = min(mini,temp);
        }
        return dp[e][f] = mini;
    }
    int superEggDrop(int e, int f) {
        vector<vector<int>>dp(e+1,vector<int>(f+1,0));
        
        for(int i=0;i<=e;i++){
            dp[i][0] = 0;
            dp[i][1] = 1;
        }
        for(int j=0;j<=f;j++){
            dp[1][j] = j;
        }
        
        for(int i=2;i<=e;i++){
            for(int j=2;j<=f;j++){
                int mini = INT_MAX;
                
                int low = 1,high = j;
                
                while(low <= high){
                    
                    int mid = (low+high)/2;
                
                    int breakk = dp[i-1][mid-1];
                    int notbreak = dp[i][j-mid];

                    int temp = 1 + max(breakk, notbreak);
                    
                    if(breakk >= notbreak){
                        high = mid-1;
                    }
                    else{
                        low = mid+1;
                    }
                    mini = min(mini,temp);  
                }
                dp[i][j] = mini; 
            }
        }
        
        return dp[e][f];
    }
};