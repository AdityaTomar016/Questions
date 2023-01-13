class Solution {
public:
    int maxi=0;
    
    int solve(int node,vector<int>adj[],string &s){
        
        int big1=0,big2=0;
        
        for(auto it: adj[node]){
            int len = solve(it,adj,s);
            
            if(s[it] == s[node]){
                continue;
            }
            
            if(len > big1){
                big2 = big1;
                big1 = len;
            }
            else if(len > big2){
                big2 = len;
            }
        }
        
        maxi = max(maxi, big1 + big2 + 1);
        
        return big1 + 1;
    }
    
    int longestPath(vector<int>& parent, string s) {
        
        int n = parent.size();
        vector<int>adj[n];
        
        for(int i=1;i<n;i++){
            adj[parent[i]].push_back(i);
        }
        
        solve(0,adj,s);
        return maxi;
    }
};