class Solution {
public:
    
    void solve(int idx,vector<int>&nums,set<vector<int>>&st){
        
        if(idx==nums.size()){
            st.insert(nums);
            return;
        }
        
        for(int i=idx;i<nums.size();i++){
            swap(nums[idx],nums[i]);
            solve(idx+1,nums,st);
            swap(nums[idx],nums[i]);
        }
        
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        vector<vector<int>>ans;
        
        set<vector<int>>st;
        solve(0,nums,st);
        
        for(auto i: st){
            ans.push_back(i);
        }
        
        return ans;
    }
};