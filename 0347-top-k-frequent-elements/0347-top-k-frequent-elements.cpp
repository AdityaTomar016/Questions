class comp{
  public:
    bool operator()(pair<int,int> &a, pair<int,int>&b){
        return a.second > b.second;
    }
};
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        
        for(auto i: nums){
            mp[i]++;
        }
        
        vector<pair<int,int>>v;
        for(auto i: mp){
            v.push_back(i);
        }
        
        sort(v.begin(),v.end(),comp());
        
        vector<int>ans;
        
        for(int i=0;i<k;i++){
            ans.push_back(v[i].first);
        }
        
        return ans;
    }
};