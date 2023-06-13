class Solution {
public:
    void solve(int i,vector<int>&ds,vector<vector<int>>&ans,vector<int>cands,int target){
        if(target == 0){
            ans.push_back(ds);
            return;
        }
        
        // while(i>0 && cands[i] == cands[i-1]) i++;
        
        for(int id=i;id<cands.size();id++){
            if(id > i && cands[id] == cands[id-1]) continue;
            
            if(target < cands[id]) break;
            
            ds.push_back(cands[id]);
            solve(id+1,ds,ans,cands,target-cands[id]);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>ds;
        
        sort(candidates.begin(),candidates.end());
        solve(0,ds,ans,candidates,target);
        
        return ans;
    }
};
