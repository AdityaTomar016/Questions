class Solution {
public:
    void solve(int i,int k,int n,vector<int>&ds,vector<vector<int>> &ans){
        if(ds.size() == k){
            ans.push_back(ds);
            return;
        }
        if(i > n){
            return;
        }
        
        
        for(int idx=i;idx<=n;idx++){
            ds.push_back(idx);
            solve(idx+1,k,n,ds,ans);
            ds.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        
        vector<vector<int>> ans;
        vector<int>ds;
        
        solve(1,k,n,ds,ans);
        return ans;
    }
};