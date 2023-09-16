class Solution {
public:
    vector<int>dx={-1,0,1,0};
    vector<int>dy = {0,1,0,-1};
    
    bool isValid(int i,int j,int n,int m){
        if(i<0 || j<0 || i>=n || j>=m) return false;
        return true;
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        
        vector<vector<int>>minAllpaths(n,vector<int>(m,INT_MAX));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        pq.push({0,{0,0,}});
        minAllpaths[0][0] = 0;
        
        while(!pq.empty()){
            auto t = pq.top();
            pq.pop();
            int prevdiff = t.first;
            int i = t.second.first;
            int j = t.second.second;
            
            if(i == n-1 && j == m-1){
                return prevdiff;
            }
            for(int it=0;it<4;it++){
                int x = i + dx[it];
                int y = j + dy[it];
                
                if(isValid(x,y,n,m)){
                    int currdiff = abs(heights[i][j] - heights[x][y]);
                    
                    if(minAllpaths[x][y] > max(prevdiff,currdiff)){
                        minAllpaths[x][y] = max(prevdiff,currdiff);
                        pq.push({minAllpaths[x][y], {x , y}});
                    }
                }
            }
        }
        return 0;
    }
};