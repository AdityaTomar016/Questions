class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int i = 0,j = 0,maxi = 0;
        unordered_set<char>set;
        
        while(i <= j && j < s.size()){
            if(set.find(s[j]) == set.end()){
                set.insert(s[j]);
                maxi = max(maxi,j-i+1);
                j++;
            }
            else{
                set.erase(s[i]);
                i++;
            }
        }
        return maxi;
    }
};