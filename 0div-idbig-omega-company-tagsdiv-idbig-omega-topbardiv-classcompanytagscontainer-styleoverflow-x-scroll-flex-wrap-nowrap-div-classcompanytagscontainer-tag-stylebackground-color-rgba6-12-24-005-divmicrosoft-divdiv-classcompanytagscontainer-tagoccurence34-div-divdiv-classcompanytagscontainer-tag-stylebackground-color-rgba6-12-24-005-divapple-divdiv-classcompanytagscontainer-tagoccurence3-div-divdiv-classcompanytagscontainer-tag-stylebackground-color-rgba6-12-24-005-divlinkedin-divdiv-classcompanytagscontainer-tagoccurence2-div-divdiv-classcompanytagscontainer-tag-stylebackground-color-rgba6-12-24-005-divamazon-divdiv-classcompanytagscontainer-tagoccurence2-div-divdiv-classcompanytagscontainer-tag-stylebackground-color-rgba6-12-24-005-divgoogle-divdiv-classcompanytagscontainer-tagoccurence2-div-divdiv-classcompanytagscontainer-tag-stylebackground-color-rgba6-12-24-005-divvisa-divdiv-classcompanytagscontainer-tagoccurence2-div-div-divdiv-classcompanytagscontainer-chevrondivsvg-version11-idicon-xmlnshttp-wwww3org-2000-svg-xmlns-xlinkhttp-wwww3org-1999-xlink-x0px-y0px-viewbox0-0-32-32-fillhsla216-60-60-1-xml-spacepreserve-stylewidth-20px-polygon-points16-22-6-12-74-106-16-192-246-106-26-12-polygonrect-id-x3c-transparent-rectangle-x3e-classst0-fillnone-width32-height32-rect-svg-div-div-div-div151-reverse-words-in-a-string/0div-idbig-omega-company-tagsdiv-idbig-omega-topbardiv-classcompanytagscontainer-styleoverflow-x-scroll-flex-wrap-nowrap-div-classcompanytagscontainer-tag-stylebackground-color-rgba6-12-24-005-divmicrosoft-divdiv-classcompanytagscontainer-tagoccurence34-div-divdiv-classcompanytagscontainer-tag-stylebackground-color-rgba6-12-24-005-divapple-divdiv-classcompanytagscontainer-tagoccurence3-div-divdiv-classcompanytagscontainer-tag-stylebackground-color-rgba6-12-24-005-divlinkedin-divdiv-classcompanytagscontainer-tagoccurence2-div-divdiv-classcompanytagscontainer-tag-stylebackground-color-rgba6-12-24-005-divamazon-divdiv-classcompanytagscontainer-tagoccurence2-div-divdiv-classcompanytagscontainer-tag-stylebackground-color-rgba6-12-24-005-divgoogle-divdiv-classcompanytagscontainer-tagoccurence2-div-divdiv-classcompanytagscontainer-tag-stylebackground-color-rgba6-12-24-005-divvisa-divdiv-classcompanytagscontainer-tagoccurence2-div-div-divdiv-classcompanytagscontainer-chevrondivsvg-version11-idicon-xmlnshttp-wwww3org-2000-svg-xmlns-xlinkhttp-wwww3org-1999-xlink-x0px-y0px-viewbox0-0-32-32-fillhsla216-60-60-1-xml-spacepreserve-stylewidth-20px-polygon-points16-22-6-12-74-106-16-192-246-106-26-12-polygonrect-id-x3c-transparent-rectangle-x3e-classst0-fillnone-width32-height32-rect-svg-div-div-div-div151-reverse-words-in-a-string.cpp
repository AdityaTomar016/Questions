class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        stack<string>st;
        
        int j=0,i=0;
        string res="";
        
        while(j<n){
            string temp="";
            while(j<n && isspace(s[j])){
                j++;
            }
            while(j<n && !isspace(s[j])){
                temp += s[j];
                j++;
            }
            
            if(temp.size())
            res = temp + " " + res;
            j++;
        }
        
        res.pop_back();
        return res;
    }
};