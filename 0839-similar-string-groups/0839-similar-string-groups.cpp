class Solution {
public:
    
    bool similar(string a,string b){
        int cnt = 0;
        
        for(int i=0;i<a.size();i++){
            if(a[i] != b[i]){
                cnt++;
            }
        }
        
        return (cnt == 2 || cnt == 0);
    }
    void dfs(int i,vector<string>& strs,vector<int>& vis){
        vis[i] = 1;
        
        for(int j=0;j<strs.size();j++){
            if(vis[j]) continue;
            
            if(similar(strs[i],strs[j])){
                dfs(j,strs,vis);
            }
        }
    }
    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        
        vector<int>vis(n,0);
        int group = 0;
        
        for(int i=0;i<n;i++){
            
            if(vis[i]) continue;
            
            group++;
            dfs(i,strs,vis);
        }
        
        return group;
    }
};