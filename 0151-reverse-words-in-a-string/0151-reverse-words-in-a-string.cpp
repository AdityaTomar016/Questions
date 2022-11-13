class Solution {
public:
    string reverseWords(string s) {
        
        string ans="";
        int n = s.size();
        for(int i=n-1;i>=0;i--){
            
            if(isspace(s[i])) continue;
            
            string temp="";
            
            while(i >= 0 && !isspace(s[i])){
                temp+=s[i];
                i--;
            }
            reverse(temp.begin(),temp.end());
            
            ans += temp + " ";
        }
        
        for(int i=ans.size()-1;i>=0;i++){
            if(isspace(ans[i])){
                ans.pop_back();
            }
            else break;
        }
        return ans;
    }
};