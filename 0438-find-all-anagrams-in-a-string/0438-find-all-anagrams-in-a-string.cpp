class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
        int n = s.size();
        int m = p.size();
        
        if(m > n) return {};
        
        vector<int>ans;
        
        vector<int>s_hash(26,0),p_hash(26,0);
        
        for(int i=0;i<m;i++){
            s_hash[s[i]-'a']++;
            p_hash[p[i]-'a']++;
        }
        
        if(p_hash == s_hash) ans.push_back(0);
        
        for(int i=m;i<n;i++){
            s_hash[s[i-m]-'a']--;
            s_hash[s[i]-'a']++;
            
            if(p_hash == s_hash){  
                ans.push_back(i-m+1);
            }
        }
        
        return ans;
    }
};