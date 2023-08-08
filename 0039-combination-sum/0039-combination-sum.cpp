class Solution {
public:
    void solve(int i,vector<int>& cands, int target,vector<int>&ds,vector<vector<int>>&ans){
        if(i == cands.size()){
            if(target == 0){
                ans.push_back(ds);    
            }
            return;
        }
        // if(target < 0) return;
        
        if(cands[i] <= target){
            ds.push_back(cands[i]);
            solve(i,cands,target-cands[i],ds,ans);
            ds.pop_back();
        }
        solve(i+1,cands,target,ds,ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int>ds;
        
        solve(0,candidates,target,ds,ans);
        return ans;
    }
};