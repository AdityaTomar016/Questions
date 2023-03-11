class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        for(int i=nums.size()-1;i>=0;i--){
            if(nums[i] == 0){
                int j = i;
                while(j + 1 < nums.size()){
                    swap(nums[j],nums[j+1]);
                    j++;
                }
            }
        }
    }
};