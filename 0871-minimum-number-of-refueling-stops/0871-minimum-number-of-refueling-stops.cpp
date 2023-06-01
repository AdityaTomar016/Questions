class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        
        int n = stations.size();        priority_queue<int,vector<int>>pq;
        
        int i=0,stops=0;
        
        while(startFuel < target){
            
            while(i<n && startFuel >= stations[i][0]){
                pq.push(stations[i][1]);
                i++;
            }
            
            if(pq.empty()){
                return -1;
            }
            
            startFuel += pq.top();
            pq.pop();
            stops++;
        }
        return stops;
    }
};