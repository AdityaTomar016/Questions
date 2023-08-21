class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        
        int leftmax=height[0], rightmax=height[n-1];
        int left=0,right=n-1;
        int water=0;
        
        while(left <= right){
            if(leftmax < rightmax){
                if(height[left] < leftmax){
                    water += leftmax-height[left];
                }       
                else{
                    leftmax = height[left];
                }
                left++;
            }
            else{
                if(height[right] < rightmax){
                    water += rightmax - height[right];
                }
                else{
                    rightmax = height[right];
                }
                right--;
            }
        }
        return water;
    }
};