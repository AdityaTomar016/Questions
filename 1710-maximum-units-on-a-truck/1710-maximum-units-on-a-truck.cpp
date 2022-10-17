class Solution {
public:
    static bool comp(vector<int>&a,vector<int>&b){
        return a[1] > b[1];
    }
    int maximumUnits(vector<vector<int>>& boxtypes, int truckSize) {
        
        sort(boxtypes.begin(),boxtypes.end(),comp);
        
        int ans=0;
        
        for(int i=0;i<boxtypes.size();i++){
            
            int x = min(truckSize,boxtypes[i][0]);
            ans += x * boxtypes[i][1];
            truckSize -= x;
            
            if(!truckSize) break;
        }
        return ans;
    }
};