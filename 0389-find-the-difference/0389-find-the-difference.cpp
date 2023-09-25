class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char,int>mp;
        for(auto i: s){
            mp[i]++;
        }
        
        for(auto i: t){
            if(mp.find(i) == mp.end() || mp[i] == 0){
                return i;
            }
            mp[i]--;
        } 
        
        return '1';
    }
};