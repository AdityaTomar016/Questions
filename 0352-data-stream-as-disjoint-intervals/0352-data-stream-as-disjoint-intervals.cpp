class SummaryRanges {
public:
    set<int>set;
    
    SummaryRanges() {
        
    }
    
    void addNum(int value) {
        set.insert(value);
    }
    
    vector<vector<int>> getIntervals() {
        
        vector<vector<int>> ans;
            
        if(set.size() == 0){
            return {};
        }
        int left = -1, right = -1;
        
        for(auto val : set){
            if(left < 0){
                left = val;
                right = val;
            }
            else if(val == right+1){
                right = val;
            }
            else{
                ans.push_back({left,right});
                left = val;
                right = val;
            }
        }
        ans.push_back({left,right});
        return ans;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */