class Solution {
public:
    
    int nthUglyNumber(int n) {
        
        priority_queue<long long,vector<long long>,greater<long long>>pq;
        pq.push(1);
        
        for(int i=0;i<n-1;i++){
            long long x = pq.top();
            pq.pop();
            
            while(!pq.empty() && pq.top() == x){
                pq.pop();
            }
            
            pq.push(x*2);
            pq.push(x*3);
            pq.push(x*5);
        }
        
        return pq.top();
    }
};