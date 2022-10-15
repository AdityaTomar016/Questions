class Solution {
public:
    bool ispalindrome(string s){
        int l=0,r=s.size()-1;
        while(l<r){
            if(s[l]!=s[r]){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
    void solve(int idx,string s, vector<string>&ds, vector<vector<string>>&ans){
        
        if(idx==s.size()){
            ans.push_back(ds);
            return;
        }
        
        for(int i=idx;i<s.size();i++){
            
            if(ispalindrome(s.substr(idx,i-idx+1))){
                
            ds.push_back(s.substr(idx,i-idx+1));
            solve(i+1,s,ds,ans);
            ds.pop_back();
            }
            
        }
    }
    vector<vector<string>> partition(string s) {
        
        vector<vector<string>>ans;
        vector<string>ds;
        solve(0,s,ds,ans);
        return ans;
    }
};