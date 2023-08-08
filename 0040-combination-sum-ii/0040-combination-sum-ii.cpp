class Solution {
public:
    void solve(int i,vector<int>& cands, int target,vector<int>&ds,vector<vector<int>>&ans){
        
        if(target == 0){
            ans.push_back(ds);
        }
        
        for(int idx=i;idx<cands.size();idx++){
            if(idx != i && cands[idx] == cands[idx-1]){
                continue;
            }
            if(cands[idx] <= target){
                ds.push_back(cands[idx]);
                solve(idx+1,cands,target-cands[idx],ds,ans);
                ds.pop_back();
            }
        }        
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>ds;
        
        sort(candidates.begin(),candidates.end());
        
        solve(0,candidates,target,ds,ans);
        
        return ans;
    }
};