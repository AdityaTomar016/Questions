class Solution {
public:
//     bool solve(int i,int jumps,vector<int>&stones,vector<vector<int>>&dp){
        
//         if(i==stones.size()-1) return true;
        
//         if(dp[i][jumps]!=-1) return dp[i][jumps];
        
//         bool ans = false;
        
//         for(int ind = i+1;ind<stones.size();ind++){
            
//             if(stones[ind] - stones[i] > jumps+1){
//                 break;
//             }
            
//             for(int t=-1;t<2;t++){
//                 if(stones[ind] - stones[i] == jumps+t){
//                     ans = ans || solve(ind,jumps+t,stones,dp);
//                 }
//             }
//         }
//         return dp[i][jumps] = ans;
//     }
    
    bool canCross(vector<int>& stones) {
        
        int n = stones.size();
        
        unordered_map<int,unordered_set<int>>mp;
        
        unordered_set<int>st;
        
        for(auto it: stones){
            mp[it] = st;
        }
        
        mp[stones[0]].insert(1);
        
       for(int i=0;i<n;i++){
           
           int currStone = stones[i];
           
           for(auto jump: mp[currStone]){
               
               int pos = currStone + jump;
               
               if(pos == stones[n-1]) return true;
               
               if(mp.find(pos)!=mp.end())
                {
                    if(jump-1>0){
                        mp[pos].insert(jump-1);
                    }
                    mp[pos].insert(jump);
                    mp[pos].insert(jump+1);
                }
               
           }
       }
        return false;
    }
};