class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        int n = nums.size();
        sort(nums.begin(),nums.end());
        
        int st=0;
        
        vector<vector<int>>ans;
        
        if(nums[0] > 0){
            return {};
        }
        
        while(st < n){
            
            if(nums[st] > 0){
                break;
            }
            
            if(st > 0 && nums[st] == nums[st-1]){
                st++;
                continue;
            }
            
            int low = st+1,high=n-1;
            
            while(low < high){
                
                if(nums[low] + nums[high] == -nums[st]){
                    ans.push_back({nums[st],nums[low],nums[high]});
                    int lastlow = nums[low];
                    int lasthigh = nums[high];

                    while(low<high && nums[low]==lastlow){
                        low++;
                    }
                    while(low<high && nums[high]==lasthigh){
                        high--;
                    }
                }
                else if(nums[low] + nums[high] < -nums[st]){
                    low++;
                }
                else high--;
            }
           
            
            st++;
        }
        
        return ans;
    }
};