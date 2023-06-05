class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int idx = -1;
        int n = nums.size();
        
        for(int i=n-2;i>=0;i--){
            if(nums[i] < nums[i+1]){
                idx = i;
                break;
            }
        }
        
        if(idx == -1){
            reverse(nums.begin(),nums.end());
            return;
        }
        
        for(int i=n-1;i>=0;i--){
            if(nums[i] > nums[idx]){
                swap(nums[i],nums[idx]);
                break;
            }
        }
        
        reverse(nums.begin()+idx+1,nums.end());
    }
};