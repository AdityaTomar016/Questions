class Solution {
public:
    int solve(int i,unordered_set<int>set, vector<int>& costs,vector<int> &dp){
        
        if(i > 365){
            return 0;
        }
        
        if(dp[i] != -1){
            return dp[i];
        }
        
        int money = 0;
        
        if(set.find(i) == set.end()){
            money = solve(i+1,set,costs,dp);
        }
        else{
            int m = INT_MAX;
            
            for(int j=0;j<costs.size();j++){
                int curr = costs[j];
                if(j == 0){
                    curr += solve(i+1,set,costs,dp);
                }
                else if(j == 1){
                    curr += solve(i+7,set,costs,dp);
                }
                else{
                    curr += solve(i+30,set,costs,dp);
                }
                
                m = min(m,curr);
            }
            
            money = m;
        }
        
        return dp[i] = money;
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        
        vector<int>dp(366,-1);
        
        unordered_set<int>set;
        for(auto i: days){
            set.insert(i);
        }
        return solve(1,set,costs,dp);
    }
};