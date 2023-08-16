class Solution {
public:
    void solve(int i,int k,vector<int>&v,vector<int>&ds,vector<vector<int>> &ans){
        if(ds.size() == k){
            ans.push_back(ds);
            return;
        }
        if(i == v.size()){
            return;
        }
        
        
        for(int idx=i;idx<v.size();idx++){
            ds.push_back(v[idx]);
            solve(idx+1,k,v,ds,ans);
            ds.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int>v;
        for(int i=1;i<=n;i++){
            v.push_back(i);
        }
        vector<vector<int>> ans;
        vector<int>ds;
        
        solve(0,k,v,ds,ans);
        return ans;
    }
};