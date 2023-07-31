class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int count=0,majority;
        
        for(int i=0;i<n;i++){
            if(count == 0){
                majority = nums[i];
                count++;
            }
            else if(nums[i] == majority){
                count++;
            }
            else{
                count--;
            }
        }
        return majority;
    }
};