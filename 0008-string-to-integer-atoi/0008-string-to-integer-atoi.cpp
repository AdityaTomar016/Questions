class Solution {
public:
    int myAtoi(string s) {
        bool pos = true;
        double num=0;
        int n=s.size(), i=0;
        
        while(i<n && s[i] == ' ') i++;
        
        if(s[i] == '-'){ 
            pos=false;
            i++;
        }
        else if(s[i] == '+'){
            pos=true;
            i++;
        }
        else if(!isdigit(s[i])) return 0;
        
        while(isdigit(s[i])){
            num = num*10 + s[i]-'0';
            i++;
        }
         
        if(!pos) num = num*-1;
        
        if(num > INT_MAX) return INT_MAX;
        if(num < INT_MIN) return INT_MIN;
        
        return num;
    }
};