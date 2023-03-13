class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        
        int ans = INT_MIN;
        int st = 0, end = n-1;
        
        while(st < end){
            int area = min(height[st],height[end])*(end-st);
            
            ans = max(ans,area);
            
            if(height[st] < height[end]){
                st++;
            }
            else end--;
        }
        return ans;
    }
};