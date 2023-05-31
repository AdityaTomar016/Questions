class UndergroundSystem {
public:
    map<pair<string,string>,vector<int>>timing;
    unordered_map<int,pair<string,int>>travel;
    
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        travel[id] = {stationName,t};
    }
    
    void checkOut(int id, string stationName, int t) {
        int diff = t-travel[id].second;
        timing[{travel[id].first,stationName}].push_back(diff);
    }
    
    double getAverageTime(string startStation, string endStation) {
        int sum=0;
        for(auto i: timing[{startStation,endStation}]){
            sum += i;
        }
        
        return (double)sum/(timing[{startStation,endStation}].size());
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */