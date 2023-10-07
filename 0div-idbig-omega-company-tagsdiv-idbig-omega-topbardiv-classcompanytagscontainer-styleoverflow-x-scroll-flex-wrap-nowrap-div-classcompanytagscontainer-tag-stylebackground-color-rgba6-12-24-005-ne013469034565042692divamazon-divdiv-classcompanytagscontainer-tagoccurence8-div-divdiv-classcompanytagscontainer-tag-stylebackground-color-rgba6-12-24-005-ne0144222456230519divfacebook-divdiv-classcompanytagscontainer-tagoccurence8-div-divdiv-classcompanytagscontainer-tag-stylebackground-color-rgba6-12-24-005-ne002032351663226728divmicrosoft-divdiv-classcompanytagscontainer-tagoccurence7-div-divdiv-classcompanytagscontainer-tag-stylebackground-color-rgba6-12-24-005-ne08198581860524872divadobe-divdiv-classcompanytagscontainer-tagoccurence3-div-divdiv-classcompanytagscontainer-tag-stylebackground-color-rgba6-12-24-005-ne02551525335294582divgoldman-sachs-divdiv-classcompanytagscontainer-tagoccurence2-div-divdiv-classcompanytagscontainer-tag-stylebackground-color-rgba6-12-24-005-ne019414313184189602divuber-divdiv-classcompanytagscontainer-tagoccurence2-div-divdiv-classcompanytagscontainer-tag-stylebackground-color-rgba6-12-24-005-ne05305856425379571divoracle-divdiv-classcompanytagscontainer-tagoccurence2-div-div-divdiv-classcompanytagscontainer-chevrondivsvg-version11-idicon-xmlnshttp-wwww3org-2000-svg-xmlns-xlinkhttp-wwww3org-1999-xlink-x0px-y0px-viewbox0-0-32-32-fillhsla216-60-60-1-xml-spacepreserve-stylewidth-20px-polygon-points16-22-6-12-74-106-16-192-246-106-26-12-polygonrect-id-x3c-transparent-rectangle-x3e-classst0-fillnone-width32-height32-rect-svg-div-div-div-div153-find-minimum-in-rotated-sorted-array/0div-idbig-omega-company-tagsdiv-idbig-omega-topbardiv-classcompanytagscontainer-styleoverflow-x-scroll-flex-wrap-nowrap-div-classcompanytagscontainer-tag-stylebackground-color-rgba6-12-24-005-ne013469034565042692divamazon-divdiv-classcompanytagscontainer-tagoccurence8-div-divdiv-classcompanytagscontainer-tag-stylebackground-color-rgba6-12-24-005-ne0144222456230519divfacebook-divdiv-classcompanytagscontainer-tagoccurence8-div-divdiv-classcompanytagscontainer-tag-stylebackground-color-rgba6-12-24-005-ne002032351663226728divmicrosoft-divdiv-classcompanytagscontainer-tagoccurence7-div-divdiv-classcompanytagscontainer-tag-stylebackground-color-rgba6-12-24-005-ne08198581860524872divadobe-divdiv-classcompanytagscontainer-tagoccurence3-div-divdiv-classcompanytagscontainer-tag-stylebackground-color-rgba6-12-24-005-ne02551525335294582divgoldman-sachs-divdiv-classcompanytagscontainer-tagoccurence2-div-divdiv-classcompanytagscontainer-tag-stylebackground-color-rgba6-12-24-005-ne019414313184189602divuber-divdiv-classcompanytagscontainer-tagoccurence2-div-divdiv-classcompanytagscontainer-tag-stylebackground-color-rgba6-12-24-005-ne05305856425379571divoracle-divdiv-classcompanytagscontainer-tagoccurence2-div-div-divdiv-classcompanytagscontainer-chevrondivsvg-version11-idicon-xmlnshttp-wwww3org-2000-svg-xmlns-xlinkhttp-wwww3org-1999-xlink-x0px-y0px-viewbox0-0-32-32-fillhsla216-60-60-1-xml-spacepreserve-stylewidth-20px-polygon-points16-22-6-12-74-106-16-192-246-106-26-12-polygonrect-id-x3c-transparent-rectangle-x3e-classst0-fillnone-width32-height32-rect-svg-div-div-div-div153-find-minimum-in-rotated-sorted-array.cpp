class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size()-1;
        int mini = INT_MAX;
        
        while(low <= high){
            int mid = (low+high)/2;
            
            if(nums[mid] >= nums[low]){
                mini = min(mini,nums[low]);
                if(nums[low] >= nums[high]){
                    low = mid+1;
                }
                else{
                    high = mid-1;
                }
            }
            else{
                mini = min(mini, nums[mid]);
                if(nums[low] >= nums[high]){
                    high = mid-1;
                }
                else{
                    low = mid+1;
                }
            }
        }
        return mini;
    }
};