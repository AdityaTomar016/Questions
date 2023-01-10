class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        
        int n = points.size();
        
        if(n <= 2) return n;
        
        int res = 0;
        
        for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
          
            int count = 2;
          
            for(int k=j+1;k<n;k++ ){
          
                int slope1 = (points[j][1] - points[i][1]) * (points[k][0] - points[i][0]);
                int slope2 = (points[k][1] - points[i][1]) * (points[j][0] - points[i][0]);
                if(slope1 == slope2){
                    count++;
                }
            }
            res = max(res,count);
            }
        }
       
    return res;
    }
};