class Solution {
public:
    int minCost(string s, vector<int>& cost) {
        
        int ans=0, mx=0, sum=0, n=s.size();
        
        for (int i = 0; i < n; ++i) {
            
            if (i > 0 && s[i] != s[i-1]){
                ans += sum - mx;
                sum = 0;
                mx = 0;
            }
            sum += cost[i];
            mx = max(mx, cost[i]);
        }
        ans += sum - mx;
        return ans;
    
    }
};
// a a a b c d e
// 1 2 3 4 5 6 7

// sum = 1+2+3 = 6
// max = 3;

// res = 6-3 = 3
    