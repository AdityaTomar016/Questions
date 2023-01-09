class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        
        int n = capital.size();
        
        vector<pair<int,int>>v;
        
        for(int i=0;i<n;i++){
            v.push_back({capital[i],profits[i]});
        }
        
        sort(v.begin(),v.end());
        priority_queue<int,vector<int>>pq;
            
        int idx=0;
        while(k--){
            while(idx < n && v[idx].first <= w){
                pq.push(v[idx].second);
                idx++;
            }
            
            if(pq.empty()) break;
            
            w += pq.top();
            pq.pop();
        }
        return w;
    }
};