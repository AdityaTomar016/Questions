class Solution {
public:
   
   
    
    vector<int> solve(int node,int par,vector<int>&ans,string &labels,vector<vector<int>>&adj){
        
        vector<int>freq(26,0);
        freq[labels[node]-'a'] = 1;
        
        for(auto& it: adj[node]){
            if(it == par){
                continue;
            }
            vector<int>child = solve(it,node,ans,labels,adj);
            
            for(int i=0;i<26;i++){
                freq[i] += child[i];
            }
        }
        
        ans[node] = freq[labels[node] -'a'];
        return freq;
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        
        vector<vector<int>>adj(n);
        
        for(auto i: edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        
        vector<int>ans(n,0);
        solve(0,-1,ans,labels,adj);
        
        return ans;
    }
};