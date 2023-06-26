#define ll long long
class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int cand) {
        
        int n = costs.size();
        
        
        priority_queue<ll,vector<ll>,greater<ll>>pq1;
        
        priority_queue<ll,vector<ll>,greater<ll>>pq2;
        
        int i=0,j=n-1;
        ll totalcost=0;
        
        int count=0;
        
        while(count<cand){
            pq1.push(costs[i++]);
            count++;
        }
        
        if(cand > costs.size()-cand){
            cand = costs.size()-cand;
            
        }
        
        count=0;
        
        while(count<cand){
            pq2.push(costs[j--]);
            count++;
        }
        
        
        
        
        while(k--){
            
            bool flag = true;
            
            if(pq1.empty()){
                totalcost += pq2.top();
                pq2.pop();
                
                flag = false;
            }
            else if(pq2.empty()){
                totalcost += pq1.top();
                pq1.pop();
            }
            else if(pq2.top() < pq1.top()){
                totalcost += pq2.top();
                pq2.pop();
                
                flag = false;
            }
            else{
                totalcost += pq1.top();
                pq1.pop();
                
            }
            
            if(flag){
                if(i <= j){
                    pq1.push(costs[i++]);
                }
            }
            else{
                if(i <= j){
                    pq2.push(costs[j--]);
                }
            }
        }
        
        return totalcost;
    }
};