class Solution {
public:
    void pitable(string needle,vector<int>&lps){
        
        int n = needle.size();
        int i = 1, len = 0;
        
        while(i < n){
            
            if(needle[i] == needle[len]){
                len++;
                lps[i] = len;
                i++;
            }
            else if(len != 0){
                len = lps[len-1];
            }
            else{
                lps[i] = 0;
                i++;
            }
        }
    }
    int strStr(string haystack, string needle) {
        
        int n = haystack.size();
        int m = needle.size();
        
        if(n == 0){
            return 0;
        }
        vector<int>lps(m,0);
        
        pitable(needle,lps);
        
        int i=0,j=0;
        
        while(i < n){
            
            if(haystack[i] == needle[j]){
                i++;
                j++;
            }
            
            if(j == m){
                return i - j;
            }
            
            if(i < n && haystack[i] != needle[j]){
                if(j == 0){
                    i++;
                }
                else{
                    j = lps[j-1];
                }
            }
        }
        return -1;
    }
};