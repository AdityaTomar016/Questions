class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int j=0,i=0,n=nums.size(),maxi=0;
        
        while(i<=j && j<n){
            if(nums[j] == 1){
                j++;
                maxi = max(maxi,j-i);
            }
            else{
                j++;
                i = j;
            }
        }
        
        return maxi;
    }
};