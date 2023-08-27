class Solution {
public:
    bool isNumber(string s) {
        
        int n = s.size();
        
        int num=0,dot=0;
        int i=0;
        while(i<n && isspace(s[i])){
            i++;
        }
        if(s[i] == '+' || s[i] == '-'){
            i++;
        }
        while(i<n && (isdigit(s[i]) || s[i] == '.')){
            if(isdigit(s[i])){
                num++;
            }
            else{
                dot++;
            }
            i++;
        }
        
        if(!num || dot>1){
            return false;
        }
        
        if(s[i] == 'e' || s[i] == 'E'){
            
            i++;
            
            if(s[i] == '+' || s[i] == '-'){
                i++;
            }
            
            int num=0;
            
            while(i<n && isdigit(s[i])){
                num++;
                i++;
            }
            
            if(!num) return false;
        }
        
        while(i<n && isspace(s[i])){
            i++;
        }
        
        return i==n;
    }
};