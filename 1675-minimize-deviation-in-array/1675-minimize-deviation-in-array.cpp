class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        
        priority_queue<int,vector<int>>pq;
        
        int mini = INT_MAX,ans = INT_MAX;
        
        for(auto i: nums){
            if(i%2){
                i = i*2;
            }
            pq.push(i);
            mini = min(mini,i);
        }
        
        while(pq.top()%2 == 0){
            int x = pq.top();
            pq.pop();
            
            ans = min(ans,x - mini);
            
            x /= 2;
            pq.push(x);
            mini = min(mini,x);
        }
        
        return min(ans,pq.top()-mini);
    }
};

// 3 8