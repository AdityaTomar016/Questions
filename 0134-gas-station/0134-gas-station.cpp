class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalsum = 0;
        int currsum = 0;
        int n = gas.size();
        int start=0;
        
        for(int i=0;i<n;i++){
            
            totalsum += gas[i]-cost[i];
            currsum += gas[i]-cost[i];
            
            if(currsum < 0){
                currsum = 0;
                start = i+1;
            }
        }
        
        if(totalsum < 0) 
            return -1;
        
        return start;
    }
};

