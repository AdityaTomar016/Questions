class comp{
    public:
  bool operator()(string &a, string &b){
      return a.size() < b.size();
  }  
};
class Solution {
public:
    bool predecessor(string &pre,string &curr){
        if(curr.size() != pre.size()+1) return false;
        bool flag=true;
        int i=0,j=0;
        
        while(i<pre.size() && j<curr.size()){
            if(pre[i] == curr[j]){
                i++;
                j++;
            }
            else if(flag){
                flag = false;
                j++;
            }
            else{
                return false;
            }
        }
        return true;
    }
    int solve(int idx,vector<string>&words,vector<int> &dp){
        if(idx == words.size()){
            return 0;
        }
        if(dp[idx] != -1) return dp[idx];
        
        int take=1;
        
        for(int i=idx+1;i<words.size();i++){
            if (words[i].size() - words[idx].size() > 1) {
                break;
            }
            if(predecessor(words[idx],words[i])){
                take = max(take, 1 + solve(i,words,dp));
            }        
        }
        
        return dp[idx] = take;
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),comp());
        vector<int>dp(words.size(),-1);
        
        int ans = 0;
        
        for(int i=0;i<words.size();i++){
            ans = max(ans , solve(i,words,dp));
        }
        return ans;
    }
};