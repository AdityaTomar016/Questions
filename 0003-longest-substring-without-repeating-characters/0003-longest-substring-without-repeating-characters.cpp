class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxi = 0;
        
        int n = s.size();
        int i=0,j=0;
        
        unordered_map<char,int>mp;
        
        while(j<n){
            if(mp.find(s[j]) != mp.end()){
                i = max(mp[s[j]]+1,i);
            }
            
            mp[s[j]] = j;
            j++;
            maxi = max(maxi,j-i);
            
        }
        
        return maxi;
    }
};