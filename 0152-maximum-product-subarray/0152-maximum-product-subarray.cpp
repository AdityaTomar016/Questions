class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int maxi = INT_MIN;
        int leftmax = 1;
        int rightmax = 1;
        
        bool haszero = false;
        
        for(int i=0;i<nums.size();i++){
            if(nums[i] == 0){
                leftmax = 1;
                haszero = true;
                continue;
            }
            leftmax *= nums[i];
            maxi = max(maxi,leftmax);
        }
        
        for(int i=nums.size()-1;i>=0;i--){
            if(nums[i] == 0){
                rightmax = 1;
                haszero = true;
                continue;
            }
            
            rightmax *= nums[i];
            maxi = max(maxi,rightmax);
        }
        
        if(haszero) return max(maxi,0);
        
        return maxi;
    }
};