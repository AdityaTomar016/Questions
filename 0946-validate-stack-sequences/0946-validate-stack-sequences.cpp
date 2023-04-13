class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        
        int n = pushed.size();
        int m = popped.size();
        
        // if(n != m){
        //     return false;
        // }
        
        stack<int>st;
        int j=0;
        
        for(int i=0;i<n;i++){
              st.push(pushed[i]);

            while(!st.empty() && j<m && st.top() == popped[j]){
                st.pop();
                j++;
            }  
            
        }
    
        return st.empty();
    }
};