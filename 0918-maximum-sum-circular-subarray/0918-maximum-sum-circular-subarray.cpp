class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        
        int n = nums.size();
        int curr_sum;
        int maxsum = INT_MIN,specialsum = 0;
        
        vector<int> suff(n);
        
        suff[n-1] = nums[n-1];
        curr_sum = nums[n-1];
        
        for(int i=n-2;i>=0;i--){
            curr_sum += nums[i];
            suff[i] = max(suff[i+1],curr_sum);
        }
        
        curr_sum = 0;
        
        for(int i=0;i<n;i++){
            
            curr_sum += nums[i];
            maxsum = max(maxsum,curr_sum);
            
            if(curr_sum < 0){
                curr_sum = 0;
            }
        }
        
        specialsum = nums[0];
        curr_sum = 0;
        for(int i=0;i<n-1;i++){
            curr_sum += nums[i];
            specialsum = max(specialsum, curr_sum+suff[i+1]);
        }
        
        
        return max(maxsum, specialsum);
    }
};