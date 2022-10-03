class Solution {
public:
    int findMin(vector<int>& nums) {
        
        int n = nums.size();
        
        int left=0;
        int right=n-1;
        
        int mn=nums[0];
        
        while(left<right){
            
            int mid = (left+right)/2;
            
            
            if(nums[left] < nums[right]){
                return nums[left];
            } 
            
            if(nums[left] <= nums[mid]){
                left = mid+1;
            }
            else{
                right = mid;
            }
        }
        
        return nums[left];
    }
};