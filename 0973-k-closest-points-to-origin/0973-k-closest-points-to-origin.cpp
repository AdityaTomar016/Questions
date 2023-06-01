class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    
        priority_queue<pair<double,vector<int>>,vector<pair<double,vector<int>>>,greater<pair<double,vector<int>>>>pq; 
        vector<vector<int>>ans;
        
        for(auto it: points){
            double dis = sqrt(it[0]*it[0] + it[1]*it[1]);
            pq.push({dis,{it[0],it[1]}});
        }
        
        
        while(!pq.empty() && k > 0){
            ans.push_back(pq.top().second);
            pq.pop();
            k--;
        }
        
        return ans;
    }
};