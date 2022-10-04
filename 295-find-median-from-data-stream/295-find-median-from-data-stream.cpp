class MedianFinder {
public:
    priority_queue<int,vector<int>>fq;
    priority_queue<int,vector<int>,greater<int>>sq;
    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(fq.empty() || fq.top() > num){
            fq.push(num);
        }
        else{
            sq.push(num);
        }
        
        if(fq.size() > (sq.size()+1)){
            sq.push(fq.top());
            fq.pop();
        }
        else if(sq.size() > (fq.size()+1)){
            fq.push(sq.top());
            sq.pop();
        }
    }
    
    double findMedian() {
        if(fq.size()==sq.size()){
            if(fq.empty()) return 0;
            
            else return (fq.top()+sq.top())/2.0;
        }
        else if(fq.size() > sq.size()){
            return fq.top();
        }
        else return sq.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */