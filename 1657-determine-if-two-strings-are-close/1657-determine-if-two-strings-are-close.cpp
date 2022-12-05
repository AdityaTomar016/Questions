class Solution {
public:
    bool closeStrings(string word1, string word2) {
        
        if(word1.size() != word2.size()){
            return false;
        }
        
        set<char>mp1,mp2;
        vector<int>freq1(26,0),freq2(26,0);
        
        for(auto i: word1){
           mp1.insert(i);
            freq1[i - 'a']++;
        }
        for(auto i: word2){
            mp2.insert(i);
            freq2[i - 'a']++;
        }
        
        sort(freq1.begin(),freq1.end());
        sort(freq2.begin(),freq2.end());
        
        if(mp1 == mp2 && freq1 == freq2){
            return true;
        }
        
        return false;
    }
};