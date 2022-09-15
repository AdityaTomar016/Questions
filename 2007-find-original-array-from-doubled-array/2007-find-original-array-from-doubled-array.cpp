class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        
        if(changed.size()%2==1) return {};
        
        sort(changed.begin(),changed.end());
        
        unordered_map<int,int>mp;
        vector<int>v;
        
        for(auto i: changed){
               mp[i]++; 
        }
        
        for(auto i: changed){
            if(mp[i]==0) continue;
            if(mp[2*i]==0) return {};
            
            if(mp[2*i] > 0){
                v.push_back(i);
                mp[i]--;
                mp[i*2]--;
            }
        }
        return v;
    }
};