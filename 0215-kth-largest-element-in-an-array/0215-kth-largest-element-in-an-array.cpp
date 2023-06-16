class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        priority_queue<int>pq;
        
        for(auto i: nums){
            pq.push(i);
        }
        
        while(!pq.empty() && --k){
            pq.pop();
        }
        
        if(!pq.empty()) return pq.top();
        
        return -1;
    }
};