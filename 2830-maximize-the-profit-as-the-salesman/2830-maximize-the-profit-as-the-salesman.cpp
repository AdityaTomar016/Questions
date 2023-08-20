class Solution {
public:
    vector<int>temp;
    bool find(int i,vector<vector<int>>& offers,int n){
        int low = i+1, high = temp.size()-1;
        
        while(low < high){
            int mid = (low+high)/2;
            
            if(temp[mid] <= offers[i][1]){
                low = mid+1;
            }
            else{
                high = mid;
            }
        }
        return low;
    }
    int solve(int i,vector<vector<int>>& offers,vector<int>&dp,int n){
        if(i >= offers.size()){
            return 0;
        }
        if(dp[i] != -1){
            return dp[i];
        }
        int take=0,nottake=0;
        
        int next = upper_bound(temp.begin(),temp.end(),offers[i][1]) - temp.begin();
        
        take = offers[i][2] + solve(next,offers,dp,n);
        nottake = solve(i+1,offers,dp,n);
        
        return dp[i] = max(take,nottake);
    }
    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        sort(offers.begin(),offers.end());
        
        for(auto i: offers){
            temp.push_back(i[0]);
        }
        vector<int>dp(offers.size()+1,-1);
        
        return solve(0,offers,dp,n);
    }
};