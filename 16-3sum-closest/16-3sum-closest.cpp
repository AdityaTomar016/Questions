class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        int n = nums.size();
        sort(nums.begin(),nums.end());
        
        int mini = INT_MAX;
        int ans=0;
        
        for(int i=0;i<n-2;i++){
            
            int l=i+1,r=n-1;
            
            while(l<r){
                int sum = nums[i] + nums[l] + nums[r];
                
                if(abs(sum-target) < mini){
                    mini = abs(sum-target);
                    ans = sum;
                }
                
                if(sum < target){
                    l++;
                }
                else if(sum > target){
                    r--;
                }
                else{
                    ans = sum;
                    i=n-2;
                    break;
                }
            }
        }
        
        return ans;
    }
};