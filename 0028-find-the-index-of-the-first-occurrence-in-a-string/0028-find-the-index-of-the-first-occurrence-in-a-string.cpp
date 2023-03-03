class Solution {
public:
    int strStr(string haystack, string needle) {
        
        int n = haystack.size();
        int m = needle.size();
        
        int i=0,j=0;
        
        while(i < n){
            
            int idx=i;
            
            while(haystack[idx] == needle[j]){
                idx++;
                j++;
                
                if(j == m){
                    return i;
                }
            }
            
            j=0;
            i++;
        }
        
        return -1;
    }
};