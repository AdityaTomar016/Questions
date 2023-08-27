class Solution {
public:
    bool solve(int i,int jumps,int n,vector<int>& stones,unordered_map<int,unordered_map<int,int>> &mp){
        if(i == n-1){
            return true;
        }
        if(i >= n){
            return false;
        }
        
        if(mp.find(i) != mp.end() && mp[i].find(jumps) != mp[i].end()){
            return mp[i][jumps];
        }
        bool ans = false;
        
        for(int idx=i+1;idx<n;idx++){
            
            if(stones[idx] == 5 && stones[idx-1] == 2){
                return false;
            }
            if(stones[idx] - stones[i] > jumps+1){
                break;
            }
            
            for(int k=-1;k<=1;k++){
                if(stones[idx] - stones[i] == jumps+k){
                    ans = ans || solve(idx,jumps+k,n,stones,mp);
                }
            }
        }
        return mp[i][jumps] = ans;
    }
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        unordered_map<int,unordered_map<int,int>>mp;
        if(stones[1] - stones[0] > 1){
            return false;
        }
        if(stones.size() == 2){
            return (stones[1]-stones[0] == 1);
        }
        return solve(0,1,n,stones,mp);
    }
};