class Solution {
public:
    vector<vector<int>>ans;
    set<vector<int>>set;
    vector<int>ds;
    
    void solve(int i,int prev,vector<int>& nums){
        
        if(i == nums.size()){
            if(ds.size() > 1){
                set.insert(ds);
            }
            
            return;
        }
        
        if(nums[i] >= prev){
            ds.push_back(nums[i]);
            solve(i+1,nums[i],nums);
            ds.pop_back();
        }
        
        solve(i+1,prev,nums);
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        
        solve(0,-1e9,nums);
        
        for(auto i: set){
            ans.push_back(i);
        }
        return ans;
    }
};