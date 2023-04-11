class Solution {
public:
    string removeStars(string s) {
        int i=0;
        string ans = "";
        
        while(i < s.size()){
            if(s[i] == '*'){
                ans.pop_back();
                i++;
                continue;
            }
            ans += s[i];
            i++;
        }
        return ans;
    }
};