class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        
        if(n < 3){
            return {};
        }
        
        sort(nums.begin(),nums.end());
        
        if(nums[0] > 0){
            return {};
        }
        
        vector<vector<int>>ans;
        
        for(int k=0;k<n;k++){
            int target = -nums[k];
            int i=k+1,j=n-1;
            
            while(i<j){
                if(nums[i] + nums[j] == target){
                    ans.push_back({nums[i],nums[j],nums[k]});
                    int lastlow = nums[i];
                    while(i<j && nums[i] == lastlow){
                        i++;
                    }
                    int lasthigh = nums[j];
                    while(i<j && nums[j] == lasthigh){
                        j--;
                    }
                }
                else if(nums[i] + nums[j] > target){
                    j--;
                }
                else{
                    i++;
                }
            }
            while(k<n-1 && nums[k] == nums[k+1]) k++;
        }
        
        return ans;
    }
};