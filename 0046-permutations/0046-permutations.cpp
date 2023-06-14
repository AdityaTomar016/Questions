class Solution {
public:
    void solve(int i,vector<int> &nums,vector<vector<int>>&ans){
        
        if(i == nums.size()){
            ans.push_back(nums);
            return;
        }
        
        for(int id=i;id<nums.size();id++){
            swap(nums[id],nums[i]);
            solve(i+1,nums,ans);
            swap(nums[id],nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        solve(0,nums,ans);
        return ans;
    }
};