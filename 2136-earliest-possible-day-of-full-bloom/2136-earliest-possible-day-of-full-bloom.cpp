class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        
        int n = plantTime.size();
        vector<pair<int,int>>v;
        
        for(int i=0;i<n;i++){
            v.push_back({growTime[i],plantTime[i]});
        }
        
        
        sort(v.begin(),v.end());
        
        int ans=0;
        
        for(auto i: v){
            int g = i.first;
            int p = i.second;
            
            
            ans = max(ans,g) + p;
        }
        
        return ans;
    }
};