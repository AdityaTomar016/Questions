class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int mn=INT_MAX;
        int ans = 0;
        
        for(int i=0;i<prices.size();i++){
            
            if(mn > prices[i]){
                mn = prices[i];
            }
            
            ans = max(ans, prices[i]-mn);
        }
        return ans;
    }
};