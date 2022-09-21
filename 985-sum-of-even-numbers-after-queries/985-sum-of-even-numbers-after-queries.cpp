class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        
        int sumofEven = 0;
        vector<int>ans;
        
        for(auto i: nums){
            if(i % 2 == 0){
                sumofEven += i;
            }
        }
        
        for(auto i: queries){
            
            int val = i[0];
            int idx = i[1];
            
            if(nums[idx] % 2 == 0){
                sumofEven -= nums[idx];
            }
            
            nums[idx] += val;
            
            if(nums[idx] % 2 == 0){
                sumofEven += nums[idx];
            }
            
            ans.push_back(sumofEven);
        }
        
        return ans;
    }
};