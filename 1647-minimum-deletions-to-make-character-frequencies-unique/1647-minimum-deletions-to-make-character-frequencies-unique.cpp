class Solution {
public:
    int minDeletions(string s) {
        
        map<char,int>mp;
        unordered_set<int>st;
        
        for(auto c: s){
            mp[c]++;
        }
        
        int count=0;
        
        for(auto i: mp){
            
            int x = i.second;
            
            while(x>0 && st.find(x)!=st.end()){
                x--;
                count++;
            }
            st.insert(x);
        }
        return count;
    }
};