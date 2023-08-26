class Solution {
public:
    int calculate(string s) {
        
        int n = s.size();
        
        stack<pair<int,int>>st; //{sum,sign}
        int sum=0,sign=1;
        
        for(int i=0;i<n;i++){
            if(s[i] == '('){
                st.push({sum,sign});
                sum = 0;
                sign = +1;
            }
            else if(isdigit(s[i])){
                long long num=0;
                
                while(i<n && isdigit(s[i])){
                    num = num*10 + s[i]-'0';
                    i++;
                }
                i--;
                sum += num*sign;
                sign = 1;
            }
            else if(s[i] == '-'){
                sign = sign*(-1);
            }
            else if(s[i] == ')'){
                sum = st.top().first + st.top().second*sum;
                st.pop();
            }
        }
        
        return sum;
    }
};