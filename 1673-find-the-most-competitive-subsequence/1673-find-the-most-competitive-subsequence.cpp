class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        
        int n = nums.size();
        vector<int>ans;
        
        stack<int>st;
        
        for(int i=0;i<n;i++){
            while(!st.empty() && nums[i] < st.top() && n-i-1 >= k-st.size()){
                st.pop();
            }
            
            if(st.size() < k)
            st.push(nums[i]);
        }
        
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
};