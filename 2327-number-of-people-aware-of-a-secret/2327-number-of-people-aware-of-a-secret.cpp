class Solution {
public:
    
    int mod = 1e9+7;
    int peopleAwareOfSecret(int n, int delay, int forget) {
        
        vector<long long>days(n+1,0);
        days[1] = 1;
        
        for(int i=1;i<=n;i++){
            for(int j=i+delay;j<i+forget && j<=n;j++){    
                
                
                days[j] = (days[j] + days[i])%mod;
            
            }
        }
        
        int i=0;
        long long ans=0;
        
        while(forget--){
            ans = (ans + days[n-i])%mod;
            i++;
        }
        
        return ans;
    }
};
// 1-a
// 2-a
// 3-a,b
// 4-a,b,c
// 5-b,c,d
// 6-b,c,d,e,f
