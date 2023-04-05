class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
           long ans = 0;
        long sum=0;
        
        for(int i=0;i<nums.size();i++){
            
            sum += nums[i];
            long temp = ceil(double(sum) / (i + 1));
            ans = max(ans,temp);
        }
        return ans;
    }
};