class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        
        int x0 = coordinates[0][0], x1 = coordinates[1][0];
        int y0 = coordinates[0][1], y1 = coordinates[1][1];
        
        
        int dy = y1-y0;
        int dx = x1-x0;
        
        for(int i=0;i<coordinates.size();i++){
            int y = coordinates[i][1];
            int x = coordinates[i][0];
            
            if(dx*(y-y1) != dy*(x-x1)) return false;
            
        }
        
        return true;
    }
};