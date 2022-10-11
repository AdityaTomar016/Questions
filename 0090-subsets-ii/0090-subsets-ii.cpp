class Solution {
public:
    
    set<vector<int>>st;
    
    void solve(int i,vector<int>nums,vector<int>&ds){
        if(i<0){
            st.insert(ds);
            return;
        }
        
        ds.push_back(nums[i]);
        solve(i-1,nums,ds);
        ds.pop_back();
        
        int idx=i;
         while (idx < nums.size() && nums[i] == nums[idx])
            idx--;
        
        solve(idx,nums,ds);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        int n = nums.size();
        vector<int>ds;
        sort(nums.begin(),nums.end());
        solve(n-1,nums,ds);
        
        for(auto i: st){
            ans.push_back(i);
        }
        return ans;
    }
};