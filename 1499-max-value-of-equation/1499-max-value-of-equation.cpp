class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& p, int k) {
        int n = p.size();
        int ans = INT_MIN;
        
        priority_queue<pair<int,int>>pq;
        pq.push({p[0][1]-p[0][0],p[0][0]});
        
        for(int i=1;i<n;i++){
            int val = p[i][1] + p[i][0];
            
            while(!pq.empty() && p[i][0]-pq.top().second > k){
                pq.pop();
            }
            
            if(!pq.empty())  ans = max(ans, val + pq.top().first);
            
            pq.push({p[i][1]-p[i][0],p[i][0]});
        }
        return ans;
    }
};