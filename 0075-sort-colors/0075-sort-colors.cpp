class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int i=0,last=n-1,st=0;
        
        while(i<=last){
            if(nums[i] == 2){
                swap(nums[i],nums[last]);
                last--;
            }
            else if(nums[i] == 0){
                swap(nums[i],nums[st]);
                st++;
                i++;
            }
            else{
                i++;
            }
        }
    }
};