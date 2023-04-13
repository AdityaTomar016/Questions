class Solution {
public:
    string solve(string s){
        string str = "";
        
        for(int i=0;i<s.size();i++){
            if(s[i] == '#'){
                if(str.size() > 0){
                    str.pop_back();
                }
            }
            else{
                str += s[i];
            }
        }
        return str;
    }
    bool backspaceCompare(string s, string t) {
        
        string s_simp = solve(s);
        string t_simp = solve(t);
        
        return s_simp == t_simp;
    }
};