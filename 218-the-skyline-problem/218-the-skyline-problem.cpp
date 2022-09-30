class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        
        vector<vector<int>> res;
        
        int cur=0, cur_X, cur_H, len = buildings.size();
        
        priority_queue<pair<int, int>> liveBlg;
        
        while(cur<len || !liveBlg.empty()) {
            
            if (liveBlg.empty() || cur<len && buildings[cur][0] <= liveBlg.top().second) {
                
                cur_X = buildings[cur][0];
                
                while(cur<len && buildings[cur][0] == cur_X) {
                   liveBlg.push({buildings[cur][2], buildings[cur][1]});
                    cur++;
                }
            } 
            else {
                cur_X = liveBlg.top().second;
                while (liveBlg.size() && liveBlg.top().second <= cur_X)
                    liveBlg.pop();
            }
            cur_H = liveBlg.empty() ? 0 : liveBlg.top().first;
            
            if (res.empty() || (res.back()[1] != cur_H))
                res.push_back({cur_X, cur_H});
        }
        return res;
    }
};