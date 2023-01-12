class StockPrice {
public:
    unordered_map<int,int>mp;
    int curr=0;
    multiset<int>set;
    
    StockPrice() {
        
    }
    
    void update(int timestamp, int price) {
        
        if(mp.find(timestamp) != mp.end()){
            set.erase(set.find(mp[timestamp]));
        }
        
        mp[timestamp] = price;
        set.insert(price);
        curr = max(curr,timestamp);
    }
    
    int current() {
        return mp[curr];
    }
    
    int maximum() {
        auto it = set.rbegin();
        return *it;
    }
    
    int minimum() {
        auto it = set.begin();
        return *it;
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */