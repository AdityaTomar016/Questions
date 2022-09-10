class Solution {
public:
    int trap(vector<int>& heights) {
        
        int n = heights.size();
        
        int water = 0;
        
        int left=0,right=n-1;
        int leftmax=0,rightmax=0;
        
        while(left<right){
            if(heights[left] < heights[right]){
                
                if(heights[left] < leftmax){
                water += leftmax - heights[left];
            }
                else leftmax = heights[left];
                
                left++;
                
            }
            else{
                if(heights[right] < rightmax){
                water += rightmax - heights[right];
            }
                else rightmax = heights[right];
                
                right--;
            }
            
        }
   
        return water;
    }
};