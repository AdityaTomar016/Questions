class SmallestInfiniteSet {
public:
    unordered_set<int>set;
    int num = 1;
    SmallestInfiniteSet() {
        set.empty();
    }
    
    int popSmallest() {
        while(set.find(num) != set.end()){
            num++;
        }
        set.insert(num);
        int t = num;
        num++;
        return t;
    }
    
    void addBack(int n) {
        set.erase(n);
        num = min(num,n);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */