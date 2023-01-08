class Solution {
public:
    int finddis(vector<int>a,vector<int>b){
        
        return (a[0]-b[0])*(a[0]-b[0]) + (a[1]-b[1])*(a[1]-b[1]);
    }
    int numberOfBoomerangs(vector<vector<int>>& points) {
        
        
        int ans = 0;
        
        for(int i=0;i<points.size();i++){
           
            map<int,int>mp;
            
            for(int j=0;j<points.size();j++){
                
                if(i == j) continue;
                
                int dis = finddis(points[i],points[j]);
                
                mp[dis]++;
            }
            
            
            for(auto it: mp){
                
                if(it.second <= 1) continue;
                
                ans += it.second*(it.second-1);
            }
        }
        
        return ans;
    }
};