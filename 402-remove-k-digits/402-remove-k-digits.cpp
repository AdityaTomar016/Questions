class Solution {
public:
    string removeKdigits(string nums, int k) {
        
        int n = nums.size();
        
        if(n<=k) return "0";
        
        if(k==0) return nums;
        
        stack<char>st;
        
        st.push(nums[0]);

        for(int i=1;i<n;i++){
            
            while(k>0 && !st.empty() && st.top() > nums[i]){
                st.pop();
                k--;
            }
            
            st.push(nums[i]);
            
            if(st.size()==1 && nums[i]=='0'){
                st.pop();
            }
        }
        
        while(k>0 && !st.empty()){
            st.pop();
            k--;
        }
        
        string ans = "";
        
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        
        if(ans.size()==0){
            return "0";
        }
        
        return ans;
  }
};