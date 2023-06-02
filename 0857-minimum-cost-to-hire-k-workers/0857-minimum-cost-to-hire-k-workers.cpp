class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n = quality.size();
        vector<pair<double,int>>v;
        double ans = DBL_MAX;
        
        for(int i=0;i<n;i++){
            double factor = wage[i]/(double)quality[i];
            v.push_back({factor,quality[i]});
        }
        
        sort(v.begin(),v.end());
        
        priority_queue<double>pq;
            double cost=0;
        
        for(int i=0;i<n;i++){
        
            if(pq.size() < k){
                pq.push(v[i].second);
                cost += v[i].second;
            }
            else if(pq.size() == k){
                if(pq.top() > v[i].second){
                    cost -= pq.top();
                    pq.pop();

                    pq.push(v[i].second);
                    cost += v[i].second;
                }
            }
            
            
            if(pq.size() == k){
                double finalcost = cost*v[i].first;
                ans = min(ans,finalcost);
            }
            
        }
        return ans;
    }
};