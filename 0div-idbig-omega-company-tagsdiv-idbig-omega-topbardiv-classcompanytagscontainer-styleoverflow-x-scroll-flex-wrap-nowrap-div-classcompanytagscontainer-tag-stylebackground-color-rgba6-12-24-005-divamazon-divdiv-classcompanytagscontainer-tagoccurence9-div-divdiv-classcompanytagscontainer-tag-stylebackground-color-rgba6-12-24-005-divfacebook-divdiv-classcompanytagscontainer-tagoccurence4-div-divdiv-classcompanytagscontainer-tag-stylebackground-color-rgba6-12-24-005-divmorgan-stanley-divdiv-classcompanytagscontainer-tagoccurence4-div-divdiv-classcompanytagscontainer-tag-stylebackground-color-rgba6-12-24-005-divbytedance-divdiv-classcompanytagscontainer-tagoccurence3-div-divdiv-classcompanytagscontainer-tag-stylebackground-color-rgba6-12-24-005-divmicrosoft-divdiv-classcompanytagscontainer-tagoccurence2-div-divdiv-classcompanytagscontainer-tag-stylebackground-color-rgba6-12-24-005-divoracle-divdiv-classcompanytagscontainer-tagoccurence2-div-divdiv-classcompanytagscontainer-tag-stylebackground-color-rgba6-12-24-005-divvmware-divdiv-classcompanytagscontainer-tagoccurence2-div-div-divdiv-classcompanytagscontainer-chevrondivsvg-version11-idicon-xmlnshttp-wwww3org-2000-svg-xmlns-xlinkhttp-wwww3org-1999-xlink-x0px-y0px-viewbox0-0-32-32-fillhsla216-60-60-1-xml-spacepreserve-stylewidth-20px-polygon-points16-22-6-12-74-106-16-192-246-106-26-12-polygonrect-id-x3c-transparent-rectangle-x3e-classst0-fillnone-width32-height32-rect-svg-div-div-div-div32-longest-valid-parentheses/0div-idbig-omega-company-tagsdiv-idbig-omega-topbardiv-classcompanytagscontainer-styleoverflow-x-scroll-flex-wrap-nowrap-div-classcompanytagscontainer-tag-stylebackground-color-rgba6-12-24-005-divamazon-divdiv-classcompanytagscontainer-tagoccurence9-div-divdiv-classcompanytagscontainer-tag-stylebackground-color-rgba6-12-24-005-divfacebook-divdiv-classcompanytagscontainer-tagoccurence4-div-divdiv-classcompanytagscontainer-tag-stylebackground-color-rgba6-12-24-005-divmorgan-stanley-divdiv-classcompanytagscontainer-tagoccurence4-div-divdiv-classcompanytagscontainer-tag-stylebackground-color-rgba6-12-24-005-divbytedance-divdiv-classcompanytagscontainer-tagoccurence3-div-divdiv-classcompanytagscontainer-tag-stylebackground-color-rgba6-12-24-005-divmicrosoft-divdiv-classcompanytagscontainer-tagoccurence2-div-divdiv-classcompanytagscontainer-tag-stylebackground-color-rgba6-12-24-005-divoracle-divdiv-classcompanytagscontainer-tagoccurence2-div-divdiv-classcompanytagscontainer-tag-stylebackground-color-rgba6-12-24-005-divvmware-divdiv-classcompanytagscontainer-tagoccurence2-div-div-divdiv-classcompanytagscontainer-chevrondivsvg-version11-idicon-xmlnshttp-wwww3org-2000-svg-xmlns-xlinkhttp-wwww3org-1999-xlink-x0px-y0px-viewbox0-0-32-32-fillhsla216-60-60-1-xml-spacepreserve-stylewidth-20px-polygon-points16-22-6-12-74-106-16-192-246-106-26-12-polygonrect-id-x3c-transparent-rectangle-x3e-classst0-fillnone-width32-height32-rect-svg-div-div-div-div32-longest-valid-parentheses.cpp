class Solution {
public:
    int longestValidParentheses(string s) {
        
        int n = s.size();
        int open=0,closed=0,maxi=0;
        
        for(int i=0;i<n;i++){
            if(s[i] == '(') open++;
            else closed++;
            
            if(open == closed){
                maxi = max(maxi, 2*open);
            }
            else if(closed > open){
                open = 0;
                closed = 0;
            }
        }
        
        open = 0, closed = 0;
        
        for(int i=n-1;i>=0;i--){
            if(s[i] == '(') open++;
            else closed++;
            
            if(open == closed){
                maxi = max(maxi, 2*open);
            }
            else if(open > closed){
                open = 0;
                closed = 0;
            }
        }
        
        return maxi;
    }
};