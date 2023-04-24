class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n = stones.size();
        priority_queue<int>pq;
        
        for(auto i: stones){
            pq.push(i);
        }
        
        while(!pq.empty()){
            int a = pq.top();
            pq.pop();
            
            int b;
            if(pq.empty()){
                return a;
            }
            else{
                b = pq.top();
                pq.pop();
            }
            
            if(a == b){
                continue;
            }
            else{
                pq.push(abs(a-b));
            }
        }
        
        if(!pq.empty()){
            return pq.top();
        }
        return 0;
    }
};