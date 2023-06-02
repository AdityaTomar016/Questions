#define ll long lonog

class Solution {
public:
    void dfs(int i,int &c,vector<int>adj[],vector<int>&vis){
        vis[i] = 1;
        c++;
        
        for(auto it: adj[i]){
            if(!vis[it]){
                dfs(it,c,adj,vis);
            }
        }
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        
        vector<int>adj[n];
        
        for(int i=0;i<n;i++){
            
            long long x1,y1,r1;
            x1 = bombs[i][0];
            y1 = bombs[i][1];
            r1 = bombs[i][2];
            
            for(int j=0;j<n;j++){
                
                if(i == j) continue;
                
                long long x2,y2;
                x2 = bombs[j][0];
                y2 = bombs[j][1];
                
                double dis = sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
                
                if(dis <= r1){
                    adj[i].push_back(j);
                }
            }
        }
        
        int ans=0;
        
        for(int i=0;i<n;i++){
            int c=0;
            vector<int>vis(n,0);
            dfs(i,c,adj,vis);
            
            ans = max(ans,c);
        }
        
        return ans;
    }
};