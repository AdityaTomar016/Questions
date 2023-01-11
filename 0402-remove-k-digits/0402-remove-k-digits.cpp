class Solution {
public:
    string removeKdigits(string num, int k) {
        
        
        if(k==0) return num;
        
        if(k >= num.size()) return "0";
        
        stack<char>st;
        st.push(num[0]);
        
        for(int i=1;i<num.size();i++){
            
            while(!st.empty() && num[i] < st.top() && k>0){
                st.pop();
                k--;
            }
            
            st.push(num[i]);
            
        }
        
        while(!st.empty() && k>0){
            st.pop();
            k--;
        }
        
        string ans="";
        
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        
        reverse(ans.begin(),ans.end());
        
        int i=0;
        
        while(ans[i] == '0'){
            i++;
        }
        
        if(ans.substr(i) == ""){
            return "0";
        }
        
        return ans.substr(i);
    }
};