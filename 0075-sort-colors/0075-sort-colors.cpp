class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        int start = 0,last = nums.size()-1;
        vector<int>ans(nums.size(),1);
        
        for(auto i: nums){
            if(i == 0){
                ans[start++] = i;
            }
            else if(i == 2){
                ans[last--] = i;
            }
        }
        nums = ans;
    }
};