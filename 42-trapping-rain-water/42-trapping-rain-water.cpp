class Solution {
public:
    int trap(vector<int>& heights) {
        
        int n = heights.size();
        
        vector<int>left(n);
        vector<int>right(n);
        
        int mx = heights[0];
        
        for(int i=0;i<n;i++){
            if(heights[i]  >  mx){
                mx = heights[i];
            }
            left[i] = mx;
        }
        
        mx = heights[n-1];
        
        for(int i=n-1;i>=0;i--){
            if(heights[i]  >  mx){
                mx = heights[i];
            }
            right[i] = mx;
        }
        
        
        
        int total = 0;
        
        for(int i=0;i<n;i++){
            int water = min(left[i],right[i]) - heights[i];
            total+=water;
        }
        return total;
    }
};