class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        
        vector<vector<int>>after (2,vector<int>(k+1,0));
        vector<vector<int>>curr (2,vector<int>(k+1,0));        
        
        int profit=0;
        
        for(int i=n-1;i>=0;i--){
            for(int bs=0;bs<2;bs++){
                for(int cap=1;cap<=k;cap++){

         if(bs==1){
            int take = -prices[i] + after[0][cap];
            int nottake = after[1][cap];
            
            profit = max(nottake,take);
        }
        else {
            int take = prices[i] + after[1][cap-1];
            int nottake = after[0][cap];
            
            profit = max(nottake,take);
        }
        
        curr[bs][cap] = profit;
                }
            }
            after=curr;
        }
        
        return after[1][k];
    }
};