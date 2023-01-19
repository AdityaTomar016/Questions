class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        
        int n = barcodes.size();
        
        if(n == 1 || n == 0){
            return barcodes;
        }
        map<int,int>mp;
        priority_queue<pair<int,int>,vector<pair<int,int>>>pq;
        
        for(auto i: barcodes){
            mp[i]++;
        }
        for(auto i: mp){
            pq.push({i.second,i.first});
        }
        
        vector<int>ans;
        
        while(pq.top().first > 0){
            auto x = pq.top();
            pq.pop();
            
            ans.push_back(x.second);
            x.first--;
            
            auto y = pq.top();
            pq.pop();
            
            if(y.first > 0){
                ans.push_back(y.second);
                y.first--;
            }
            
            pq.push(x);
            pq.push(y);
        }
        return ans;
    }
};