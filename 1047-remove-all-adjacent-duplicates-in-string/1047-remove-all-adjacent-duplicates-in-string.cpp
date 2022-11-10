class Solution {
public:
    string removeDuplicates(string s) {
        
       stack<char>st;
        string ans="";
        
        for(auto i: s){
            
            if(st.empty()) st.push(i);
            
            else if(!st.empty() && st.top() == i){
                st.pop();
            }
            else st.push(i);
        }
        
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
};