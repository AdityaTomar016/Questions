class Solution {
public:
    int arraySign(vector<int>& nums) {
        
        int prod=1,n=nums.size();
        
        for(auto i: nums){
            prod = prod*i;
            
            if(prod > 0){
                prod = 1;
            }
            else if(prod < 0){
                prod = -1;
            }
            else break;
        }
        
        return prod;
    }
};