class Solution {
public:
    int trap(vector<int>& height) {
        
        int n = height.size();
        int leftmax = 0, rightmax = 0;
        
        int left=0,right=n-1;
        int water=0;
        
        
        while(left<right){
            if(height[left] < height[right]){
                if(height[left] > leftmax){
                    leftmax = height[left];
                }
                else{
                    water += leftmax-height[left];
                }
                left++;
            }
            else{
                if(height[right] > rightmax){
                    rightmax = height[right];
                }
                else{
                    water += rightmax - height[right];
                }

                right--;
            }
        }
        
        return water;
    }
};