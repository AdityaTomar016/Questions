class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        
        int n = nums.size();
        vector<pair<int,int>>v;
        
        for(int i=0;i<n;i++){
            v.push_back({nums[i],cost[i]});
        }
        
        sort(v.begin(),v.end());
        
        long long ans = LLONG_MAX;
        long long sum = v[0].second;
        
        vector<long long>prefix(n,0),suffix(n,0);
        
        for(int i=1;i<n;i++){
            prefix[i] += prefix[i-1] + abs(v[i].first - v[i-1].first)*sum;
            sum += v[i].second;
        }
        
        sum = v[n-1].second;
        
        for(int i=n-2;i>=0;i--){
            suffix[i] += suffix[i+1] + abs(v[i].first - v[i+1].first)*sum;
            sum += v[i].second;
        }
        
        for(int i=0;i<n;i++){
            ans = min(ans, prefix[i]+suffix[i]);
        }
        
        return ans;
    }
};