class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        int n = heights.size();
        
        stack<int>st;
        
        int maxA = INT_MIN;
        
        for(int i=0;i<=n;i++){
            
   while(!st.empty() && (i == n || heights[st.top()] >= heights[i])){
       
           int h = heights[st.top()];
           st.pop();
       
       int w;
       
       if(st.empty()){
           w = i;
       }
       else w = i - st.top() - 1;
       
       maxA = max(maxA, h*w);
         }
            st.push(i);
        }
        return maxA;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        
        int n = matrix.size();
        int m = matrix[0].size();
        
        vector<int>heights(m,0);
        
        int maxA = 0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                
                if(matrix[i][j]=='1') heights[j]++;
                else heights[j]=0;
            }
            int area = largestRectangleArea(heights);
            maxA = max(maxA,area);
        }
        return maxA;
    }
};