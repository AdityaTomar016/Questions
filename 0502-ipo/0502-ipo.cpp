class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        
        int n = capital.size();
        vector<pair<int,int>>v;
        
        for(int i=0;i<n;i++){
            v.push_back({capital[i],profits[i]});
        }
        
        priority_queue<int,vector<int>>pq;
        sort(v.begin(),v.end());
        
        int i = 0;
        
        while(k > 0){
            
            while(i < n && v[i].first <= w){
                pq.push(v[i].second);
                i++;
            }
            
            if(pq.empty()) break;
            
            w += pq.top();
            pq.pop();
            k--;
        }
        
        return w;
    }
};