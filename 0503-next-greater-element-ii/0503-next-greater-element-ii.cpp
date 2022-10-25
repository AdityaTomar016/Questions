class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        
        int n = nums.size();
        stack<int>st;
        vector<int>ans(n,-1);
        
        for(int i=0;i<n*2;i++){
            
            int idx = i%n;
            
            while(!st.empty() && nums[idx] > nums[st.top()]){
                ans[st.top()] = nums[idx];
                st.pop();
            }
            
            st.push(idx);
        }
        
        return ans;
    }
};