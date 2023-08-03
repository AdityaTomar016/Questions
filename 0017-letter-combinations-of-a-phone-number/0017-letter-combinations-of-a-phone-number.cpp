class Solution {
public:
    void solve(int i,string s,vector<string>&ans,unordered_map<int,string>mp,string digits){
        if(i == digits.size()){
            if(s.size()){
                ans.push_back(s);    
            }
            return;
        }
        
        for(auto it: mp[digits[i]-'0']){
//             for(int j=0;j<it.size();j++){
                
//             }
            solve(i+1,s+it,ans,mp,digits);
        }
        
    }
    vector<string> letterCombinations(string digits) {
        vector<string>ans;
        string s="";
        
        unordered_map<int,string>mp;
        mp[2] = "abc";
        mp[3] = "def";
        mp[4] = "ghi";
        mp[5] = "jkl";
        mp[6] = "mno";
        mp[7] = "pqrs";
        mp[8] = "tuv";
        mp[9] = "wxyz";
        
        solve(0,s,ans,mp,digits);
        return ans;
    }
};