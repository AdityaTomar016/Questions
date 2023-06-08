class DisjointSet{
  public:
    vector<int>par,sz;
    
    DisjointSet(int n){
        par.resize(n+1);
        sz.resize(n+1,1);
        
        for(int i=0;i<=n;i++){
            par[i] = i;
        }
    }
    
    int find_par(int u){
        if(u == par[u]) return u;
        
        return par[u] = find_par(par[u]);
    }
    
    void unionbysz(int u,int v){
        u = find_par(u);
        v = find_par(v);
        
        if(u == v){
            return;
        }
        
        if(sz[u] > sz[v]){
            par[v] = u;
            sz[u] += sz[v];
        }
        else{
            par[u] = v;
            sz[v] += sz[u];
        }
    }
};
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        int n = nums.size();
        
        DisjointSet d(n);
        unordered_map<int,int>mp;
        
        for(int i=0;i<n;i++){
            
            if(mp.find(nums[i]) != mp.end()) continue;
            
            if(mp.find(nums[i]-1) != mp.end()){
                d.unionbysz(i,mp[nums[i]-1]);
            }
            if(mp.find(nums[i]+1) != mp.end()){
                d.unionbysz(i,mp[nums[i]+1]);
            }
            mp.insert({nums[i],i});
        }
        
        int maxi = 0;
        
        for(int i=0;i<n;i++){
            maxi = max(maxi,d.sz[i]);
        }
        
        return maxi;
    }
};