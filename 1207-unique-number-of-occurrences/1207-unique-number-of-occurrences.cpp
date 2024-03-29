class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int,int>mp;
        set<int>st;
        
        for(auto i: arr){
            mp[i]++;
        }
        
        for(auto i: mp){
            st.insert(i.second);
        }
        
        if(mp.size() == st.size())
            return true;
        
        return false;
    }
};