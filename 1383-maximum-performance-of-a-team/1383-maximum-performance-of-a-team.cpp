class Solution {
public:
    int mod = 1e9+7;
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        
        vector<pair<int,int>>v;
        
        for(int i=0;i<speed.size();i++){
            v.push_back({efficiency[i],speed[i]});
        }
        
        sort(v.begin(),v.end());
        
        priority_queue<int,vector<int>,greater<int>>pq;
        
        long long sum = 0,performance = INT_MIN;
        
        for(int i=speed.size()-1;i>=0;i--){

            pq.push(v[i].second);
            sum += v[i].second;
            
            if(pq.size() > k){
                int x = pq.top();
                pq.pop();
                sum -= x;
            }    
            performance = max(performance, sum*v[i].first);
        }
      return performance%mod;
    }
};

// 1 5 2 10 3 8
// 9 7 5 4  3 2 
// 8 10
// sum = 18  
// p = 60