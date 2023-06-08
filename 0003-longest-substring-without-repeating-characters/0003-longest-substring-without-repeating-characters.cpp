class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxi = 0;
        
        int n = s.size();
        int i=0,j=0;
        
        unordered_set<char>st;
        
        while(j<n){
            while(st.find(s[j]) != st.end()){
                st.erase(s[i]);
                i++;
            }
            st.insert(s[j]);
            j++;
            maxi = max(maxi,j-i);
            
        }
        
        return maxi;
    }
};