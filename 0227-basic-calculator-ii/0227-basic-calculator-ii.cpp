class Solution {
public:
    int calculate(string s) {
        
        int n = s.size();
        
        stack<int>st;
        char ch = '+';
        
        long long num = 0;
        long long res = 0;
        
        for(int i=0;i<s.size();i++){
            
            if(isdigit(s[i])){
                num = num*10 + s[i]-'0';
            }
            
            if(!isdigit(s[i]) && !isspace(s[i]) || i == n-1){
                
                if(ch == '+'){
                    st.push(num);
                }
                else if(ch == '-'){
                    st.push(-num);
                }
                else{
                    int temp;
                    
                    if(ch == '*'){
                        temp = st.top()*num;
                    }
                    else{
                        temp = st.top()/num;
                    }
                    
                    st.pop();
                    st.push(temp);
                }
                
                ch = s[i];
                num = 0;
            }
        }
        
        while(!st.empty()){
            res += st.top();
            st.pop();
        }
        
        return res;
    }
};