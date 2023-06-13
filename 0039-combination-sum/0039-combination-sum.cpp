class Solution {
public:
    void solve(int i,vector<int>&ds,vector<vector<int>>&ans,vector<int>cands,int target){
        if(i == cands.size()){
            if(target == 0){
                ans.push_back(ds);
            }
            return;
        }
        
        if(target >= cands[i]){
            ds.push_back(cands[i]);
            solve(i,ds,ans,cands,target-cands[i]);
            ds.pop_back();
        }
        
        solve(i+1,ds,ans,cands,target);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>ds;
        
        sort(candidates.begin(),candidates.end());
        solve(0,ds,ans,candidates,target);
        
        return ans;
    }
};