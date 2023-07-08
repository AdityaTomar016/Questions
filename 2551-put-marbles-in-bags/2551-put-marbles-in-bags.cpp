class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        
        vector<long long>w;
        int n = weights.size();
        
        for(int i=0;i<n-1;i++){
            w.push_back(weights[i]+weights[i+1]);
        }
        
        sort(w.begin(),w.end());
        
        long long mini=0,maxi=0;
        
        for(int i=0;i<k-1;i++){
            
            mini += w[i];
            maxi += w[n-2-i];
        }
        
        return maxi-mini;
    }
};