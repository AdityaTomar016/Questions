class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        
        long ans=0;
        
        int lastmin=-1;
        int lastmax=-1;
        int start=0;
        
        for(int i=0;i<nums.size();i++){
            
            if(nums[i] > maxK || nums[i] < minK){
                lastmin = -1;
                lastmax = -1;
                start = i+1;
            }
            
            if(nums[i] == minK){
                lastmin = i;
            }
            if(nums[i] == maxK){
                lastmax = i;
            }
            
            ans += max(0, min(lastmin,lastmax) - start + 1);
            
        }
        
        return ans;
    }
};