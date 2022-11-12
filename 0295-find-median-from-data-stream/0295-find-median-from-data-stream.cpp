class MedianFinder {
public:
    priority_queue<int,vector<int>>fq;
    priority_queue<int,vector<int>,greater<int>>sq;
    
    MedianFinder() {
        while(!fq.empty()){
            fq.pop();
        }
        while(!sq.empty()){
            sq.pop();
        }
    }
    
    void addNum(int num) {
        if(fq.empty() || fq.top() > num){
            fq.push(num);
        }
        else{
            sq.push(num);
        }
        
        if(fq.size() > sq.size()+1){
            sq.push(fq.top());
            fq.pop();
        }
        else if(sq.size() > fq.size()+1){
            fq.push(sq.top());
            sq.pop();
        }
    }
    
    double findMedian() {
        
        if(fq.size() == sq.size()){
            
            if(fq.size() == 0) return 0;
            return (fq.top()+sq.top())/2.0;
        }
        else if(fq.size() > sq.size()){
            return fq.top()/1.0;
        }
        else return sq.top()/1.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */