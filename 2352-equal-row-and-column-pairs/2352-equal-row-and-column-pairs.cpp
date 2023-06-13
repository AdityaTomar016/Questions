class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        map<vector<int>,int>mp;
        int count=0;
        
        for(auto r: grid){
            mp[r]++;
        }
        
        for(int j=0;j<m;j++){
            vector<int>v;
            for(int i=0;i<n;i++){
                v.push_back(grid[i][j]);
            }
            
            if(mp.find(v) != mp.end()){
                count+=mp[v];
            }
        }
        
        return count;
    }
};