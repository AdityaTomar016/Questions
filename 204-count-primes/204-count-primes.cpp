class Solution {
public:
    int countPrimes(int n) {
        
        vector<long long>prime(n+1,0);
        
        for(long long i=2;i<n;i++){
            if(prime[i]==0){
                for(long long j=i*i;j<n;j+=i){
                    prime[j] = 1;
                }
            }
        }
        
        int count=0;
        
        for(int i=2;i<n;i++){
            if(prime[i]==0){
                count++;
            }
        }
        return count;
    }
};