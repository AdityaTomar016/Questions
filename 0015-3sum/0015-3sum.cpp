class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        int n = nums.size();
        sort(nums.begin(),nums.end());
        
        vector<vector<int>>ans;
        
        if(nums[0] > 0){
            return {};
        }

        for(int i=0;i<n;i++){
            int low = i+1,high=n-1;
            
            while(low<high){
                if(nums[low]+nums[high] == -nums[i]){
                    ans.push_back({nums[low],nums[high],nums[i]});
                    int lastlow = nums[low];
                    int lasthigh = nums[high];
                    while(low<high && nums[low] == lastlow) low++;  
                    while(low<high && nums[high] == lasthigh) high--;
                }
                else if(nums[low]+nums[high] > -nums[i]){
                    high--;
                }
                else {
                    low++;
                }
            }
            
             while(i<n-1 && nums[i] == nums[i+1]) i++;
        }
        
        return ans;
    }
};