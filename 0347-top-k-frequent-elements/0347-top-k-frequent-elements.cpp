class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        if(nums.size() == 0) return {};
        
        unordered_map<int,int>mp;
        
        for(auto i: nums){
            mp[i]++;
        }
        
        vector<vector<int>>bucket(nums.size()+1);
        
        for(auto i: mp){
            bucket[i.second].push_back(i.first);
        }
        
        vector<int>res;
        
        for(int i=bucket.size()-1;i>=0;i--){
            for(int j=0;j<bucket[i].size();j++){
                res.push_back(bucket[i][j]);
                
                if(res.size() == k) return res;
            }
        }
        
        return res;
    }
};