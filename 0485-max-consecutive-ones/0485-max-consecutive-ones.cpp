class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int maxi=0,i=0,j=0;
        
        while(j<n){
            while(i<n && nums[i] != 1){
                i++;
            }
            
            while(j<n && nums[j] == 1) j++;
            
            maxi = max(maxi,j-i);
            
            i = j+1;
            j = i;
        }
        
        return maxi;
    }
};