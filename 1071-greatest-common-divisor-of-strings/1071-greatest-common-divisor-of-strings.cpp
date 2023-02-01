class Solution {
public:
    bool solve(string s,int len,string divisor){
        
        int i=0;
        
        while(i < s.size()){
            string dividend = s.substr(i,len);
            
            if(divisor != dividend) return false;
            
            i += len;
        }
        
        return true;
    }
    string gcdOfStrings(string str1, string str2) {
        
        int n = str1.size();
        int m = str2.size();
        
        if(m > n){
            gcdOfStrings(str2,str1);
        }
        
        string ans = "";
        
        for(int i=0;i<m;i++){
            
            string divisor = str2.substr(0,i+1);
            int len = divisor.size();
            
            if(n % len || m % len){
                continue;
            }
            if(solve(str1,len,divisor) && solve(str2,len,divisor)){
                ans = divisor;
            }
        }
        return ans;
    }
};