class Solution {
public:
    bool solve(int i,int curr_sum,int target,int k,vector<int>&vis,vector<int>&nums){
        
        if(i >= nums.size()){
            return false;
        }
        if(k == 1){
            return true;
        }

        if(curr_sum == target){
            return solve(0,0,target,k-1,vis,nums);
        }
        
        for(int j=i;j<nums.size();j++){
            
             if(curr_sum + nums[j] <= target && !vis[j]){
                 
                 vis[j] = 1;
                 
                 if(solve(j+1,curr_sum+nums[j],target,k,vis,nums)){
                     return true;
                 }

                 vis[j] = 0;
            }
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        
        int sum = 0;
        
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
        }
        
        if(sum%k != 0){
            return false;
        }
        
        vector<int>vis(nums.size(),0);
        sort(nums.rbegin(),nums.rend());
        return solve(0,0,sum/k,k,vis,nums);
    }
};