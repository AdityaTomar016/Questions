class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        
        
        unordered_map<string,int>mp;
        
        int ans=0;
        
        for(auto i: words){
            mp[i]++;
        }
    
        
        bool flag=true;
        
        for(auto i: words){
            
            string s = i;
            reverse(s.begin(),s.end());
            
            if(i != s && mp[i]>0 && mp[s]>0){
                mp[i]--;
                mp[s]--;
                
                ans += 4;
            }
            else if(i == s && mp[i] > 1){
                mp[i]-=2;
                ans += 4;
            }
            else if(i == s && flag && mp[i] == 1){
                mp[i]--;
                ans += 2;
                flag=false;
            }
        }
    
        return ans;
    }
};