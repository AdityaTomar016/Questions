class Solution {
public:
    static bool cmp(vector<int>&v1,vector<int>&v2){
        
        return v1[1] < v2[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        if(intervals.size()==0) return 0;
        
        sort(intervals.begin(),intervals.end());
        int count = 0;
        int end = intervals[0][1];
        
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0] >= end){
                end = intervals[i][1];
            }
            else{
                count++;
                end = min(end,intervals[i][1]);
            }
        }
        return count;
    }
};

//[1,2],[1,3],[2,3],[3,4]