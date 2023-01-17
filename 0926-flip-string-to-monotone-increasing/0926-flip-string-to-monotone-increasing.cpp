class Solution {
public:
    int minFlipsMonoIncr(string s) {
        
        int flipcount=0;
        int one=0;
        
        for(int i=0;i<s.size();i++){
            
            if(s[i] == '1'){
                one++;
            }
            else{
                flipcount = min(flipcount+1,one);
            }
        }
        
       return flipcount;
    }
};