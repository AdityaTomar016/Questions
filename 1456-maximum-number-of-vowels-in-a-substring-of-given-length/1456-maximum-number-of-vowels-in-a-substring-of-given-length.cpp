class Solution {
public:
    bool isvow(char c){
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
            return true;
        }
        return false;
    }
    int maxVowels(string s, int k) {
        
        int i=0,j=0;
        int vow=0,ans = 0;
        
        while(i<=j && j<s.size()){
             if(isvow(s[j])){
                vow++;
            }
            
            if(j-i+1 < k){
                j++;
            }
            else if(j-i+1 == k){
                ans = max(ans,vow);
                if(isvow(s[i])){
                    vow--;
                }
                i++;
                j++;
            }
        }
        return ans;
    }
};