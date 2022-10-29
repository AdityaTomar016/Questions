class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        int n = heights.size();
        int ans=0;
        stack<int>st;
        int w;
        for(int i=0;i<=n;i++){
            
            while(!st.empty() && (i==n || heights[st.top()] >= heights[i])){
                
                int h = heights[st.top()];
                st.pop();
                
                if(st.empty()) w = i;
                else w = i - st.top() - 1;
                
                ans = max(ans,h*w);
                
            }
            st.push(i);
        }
        return ans;
    }
};