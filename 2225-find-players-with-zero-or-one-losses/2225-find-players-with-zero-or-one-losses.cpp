class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        
        map<int,int>mp;
        
        for(auto i: matches){
            mp[i[1]]++;
        }
        vector<int>z,o;
        for(auto i: mp){
            if(i.second == 1){
                o.push_back(i.first);
            }
        }
        
        set<int>s;
        for(auto i: matches){
            if(mp.find(i[0]) == mp.end()){
                s.insert(i[0]);
            }
        }
        
        for(auto i:s){
            z.push_back(i);
        }
        
        return {z,o};
    }
};