class Solution {
public:
    int solve(int left,int right,vector<int>& nums){
        int pivot = nums[left];
        int l = left+1;
        int r = right;
        
        while(l <= r){
            if(nums[l] <= pivot && nums[r] >= pivot){
                swap(nums[l],nums[r]);
                l++;
                r--;
            }
            else if(pivot <= nums[l]){
                l++;
            }
            else if(pivot >= nums[r]){
                r--;
            }
        }
        
        swap(nums[left],nums[r]);
        return r;
    }
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0, right = n-1;
        
        while(true){
        
            int idx = solve(left,right,nums);
            
            if(idx == k-1){
                return nums[idx];
            }
            else if(idx > k-1){
                right = idx-1;
            }
            else{
                left = idx+1;
            }
        }
        return -1;
    }
};