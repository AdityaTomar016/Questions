class Solution {
public:
    string pushDominoes(string s) {
        
        int n = s.size();
        int left=0;
        
        for(int i=0;i<n;i++){
            
            if(s[i]=='.') continue;
            
            else if((s[left] == s[i]) || (s[left]=='.' && s[i]=='L')){
                
                for(int j=left;j<i;j++){
                    s[j] = s[i]; 
                }
            }
            else if(s[left]=='L' && s[i]=='R'){
                
            }
            
            else if(s[left]=='R' && s[i]=='L'){
                
                int k = (i - left - 1) / 2;
                
                for(int j=1;j<=k;j++){
                    s[i-j] = 'L';
                    s[left+j] = 'R';
                }
            }
            left = i;
        }
        
        if(s[left] == 'R'){
            for(int j=left;j<n;j++){
                    s[j] = 'R'; 
                }
        }
        return s;
    }
};