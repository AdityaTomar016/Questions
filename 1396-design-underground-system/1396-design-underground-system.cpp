class UndergroundSystem {
public:
    map<pair<string,string>,pair<int,int>>timing;
    unordered_map<int,pair<string,int>>travel;
    
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        travel[id] = {stationName,t};
    }
    
    void checkOut(int id, string stationName, int t) {
        int diff = t-travel[id].second;
        timing[{travel[id].first,stationName}].first += diff;
        timing[{travel[id].first,stationName}].second++;
    }
    
    double getAverageTime(string startStation, string endStation) {
//         int sum=0;
//         for(auto i: timing[{startStation,endStation}]){
//             sum += i;
//         }
        
//         return (double)sum/(timing[{startStation,endStation}].size());
        return (double)timing[{startStation,endStation}].first/timing[{startStation,endStation}].second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */