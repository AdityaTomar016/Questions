class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        int n = nums.size();
        vector<vector<int>> ans;
        
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<n;i++){
            long long target1 = target - nums[i];
            for(int j=i+1;j<n;j++){
                long long target2 = target1 - nums[j];
                
                int low=j+1,high=n-1;
                
                while(low < high){
                    if(nums[low] + nums[high] == target2){
                        ans.push_back({nums[i],nums[j],nums[low],nums[high]});
                        
                        int lastlow = nums[low],lasthigh = nums[high];
                        
                        while(low<high && nums[low] == lastlow){
                            low++;
                        }
                        while(low < high && nums[high] == lasthigh){
                            high--;
                        }
                    }
                    else if(nums[low] + nums[high] < target2){
                        low++;
                    }
                    else{
                        high--;
                    }
                }
                
                while(j<n-1 && nums[j]==nums[j+1]){
                    j++;
                }
            }
            while(i<n-1 && nums[i]==nums[i+1]){
                i++;
            }
        }
        return ans;
    }
};