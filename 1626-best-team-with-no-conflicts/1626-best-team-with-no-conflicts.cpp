// static bool mycomp(pair<int,int> &a , pair<int,int> &b){
    
//     if(a.first == b.first){
//         return b.second > a.second;
//     }
    
//     return a.first < b.first;
// }
class Solution {
public:
    int solve(int i,int prev,vector<pair<int,int>> &v,vector<vector<int>> &dp){
        
        if(i == v.size()){
            return 0;
        }
        
        if(dp[i][prev+1] != -1) return dp[i][prev+1];
        
        int take=0,nottake=0;
        
        if(prev == -1 || v[i].second >= v[prev].second){
            take = v[i].second + solve(i+1,i,v,dp);
        }
        
        nottake = solve(i+1,prev,v,dp);

        
        return dp[i][prev+1] = max(take,nottake);
    }
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        
        int n = scores.size();
        
        vector<pair<int,int>>v;
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        
        for(int i=0;i<scores.size();i++){
            v.push_back({ages[i],scores[i]});
        }
        
        sort(v.begin(),v.end());
        
        
        
        return solve(0,-1,v,dp);
    }
};
// 1 8 9 10
// 5 1 2 3