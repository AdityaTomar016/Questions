class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size(),i=0,j=0;
        int count=0,maxi=0;
        
        while(i<=j && j<n){
            if(nums[j] == 0){
                count++;
            }
            while(count > k){
                if(nums[i] == 0){
                    count--;
                }
                i++;
            }
            
            j++;
            maxi = max(maxi,j-i);
        }
            
        return maxi;       
    }
};