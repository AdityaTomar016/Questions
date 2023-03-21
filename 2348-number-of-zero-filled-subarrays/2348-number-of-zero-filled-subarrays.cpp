class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        
        long long i=0,j=0;
        long long count = 0;
        
        while(j < nums.size()){
            while(j<nums.size() && nums[j] == 0){
                j++;
            }
            count += (j-i)*(j-i+1)/2;
            j++;
            i=j;
        }
        
        return count;
    }
};