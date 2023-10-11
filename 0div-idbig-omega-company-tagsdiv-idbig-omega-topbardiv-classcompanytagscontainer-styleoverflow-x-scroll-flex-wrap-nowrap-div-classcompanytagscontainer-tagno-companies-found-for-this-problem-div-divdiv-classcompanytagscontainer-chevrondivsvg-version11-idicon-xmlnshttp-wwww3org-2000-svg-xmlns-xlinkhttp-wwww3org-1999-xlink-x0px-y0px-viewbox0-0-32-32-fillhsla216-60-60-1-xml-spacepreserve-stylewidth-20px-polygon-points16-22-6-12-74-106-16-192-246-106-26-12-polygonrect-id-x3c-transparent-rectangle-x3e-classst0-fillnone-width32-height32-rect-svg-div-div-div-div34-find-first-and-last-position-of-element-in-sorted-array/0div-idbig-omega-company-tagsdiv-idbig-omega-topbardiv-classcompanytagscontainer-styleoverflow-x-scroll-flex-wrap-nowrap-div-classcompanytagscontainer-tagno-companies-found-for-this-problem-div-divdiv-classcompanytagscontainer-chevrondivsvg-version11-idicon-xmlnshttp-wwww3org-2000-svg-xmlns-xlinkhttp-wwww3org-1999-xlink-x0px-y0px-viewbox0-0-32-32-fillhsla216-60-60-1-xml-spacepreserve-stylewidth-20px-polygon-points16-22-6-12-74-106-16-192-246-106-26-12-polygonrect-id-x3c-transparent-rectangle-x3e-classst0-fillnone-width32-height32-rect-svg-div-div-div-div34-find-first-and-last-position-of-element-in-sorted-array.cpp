class Solution {
public:
    int findlowerbound(vector<int>& nums, int target){
        int low = 0, high = nums.size()-1;
        int ans = nums.size();
        
        while(low <= high){
            int mid = (low+high)/2;
            
            if(nums[mid] >= target){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        
        return ans;
    }
    int findupperbound(vector<int>& nums, int target){
        int low = 0, high = nums.size()-1;
        int ans = nums.size();
        
        while(low <= high){
            int mid = (low+high)/2;
            
            if(nums[mid] > target){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        
        int lower = findlowerbound(nums,target);
        int upper = findupperbound(nums,target);
        
        if(lower == n || nums[lower] != target){
            return {-1,-1};
        }
        else{
            return {lower,upper-1};
        }
    }
};