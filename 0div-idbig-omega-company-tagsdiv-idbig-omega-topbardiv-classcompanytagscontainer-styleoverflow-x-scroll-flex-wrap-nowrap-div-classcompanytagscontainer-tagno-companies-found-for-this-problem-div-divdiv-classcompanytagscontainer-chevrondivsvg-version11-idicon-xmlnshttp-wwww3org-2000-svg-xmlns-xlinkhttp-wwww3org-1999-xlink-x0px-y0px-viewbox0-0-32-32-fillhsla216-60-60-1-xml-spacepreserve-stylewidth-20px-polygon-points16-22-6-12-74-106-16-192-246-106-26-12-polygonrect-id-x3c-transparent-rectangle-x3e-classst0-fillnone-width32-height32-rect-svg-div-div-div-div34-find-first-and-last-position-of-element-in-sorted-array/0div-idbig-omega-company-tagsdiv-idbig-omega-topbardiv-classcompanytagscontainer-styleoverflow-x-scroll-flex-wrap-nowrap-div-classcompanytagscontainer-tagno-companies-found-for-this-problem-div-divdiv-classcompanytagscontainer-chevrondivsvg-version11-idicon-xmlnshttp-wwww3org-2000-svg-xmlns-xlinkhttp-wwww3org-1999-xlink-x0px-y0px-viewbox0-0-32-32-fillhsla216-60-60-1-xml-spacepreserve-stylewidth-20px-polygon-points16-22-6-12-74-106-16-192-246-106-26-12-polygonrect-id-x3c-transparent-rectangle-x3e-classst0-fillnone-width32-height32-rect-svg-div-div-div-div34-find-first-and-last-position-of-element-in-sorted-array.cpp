class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int first = lower_bound(nums.begin(),nums.end(),target) - nums.begin();
        int last = upper_bound(nums.begin(),nums.end(),target) - nums.begin();
        
        if(first == n || nums[first] != target){
            return {-1,-1};
        }
        
        return {first,last-1};
    }
};