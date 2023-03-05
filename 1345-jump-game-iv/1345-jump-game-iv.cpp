class Solution {
public:
//     int solve(int i,vector<int>&arr,vector<int>&vis,unordered_map<int,vector<int>>mp){
        
//         int n = arr.size();
        
//         if(i < 0 || i >= n || vis[i]){
//             return 1e9;
//         }
        
//         if(i == n-1){
//             return 0;
//         }
        
//         int mini = 1e9;
//         vis[i] = 1;
        
//         vector<int>v = mp[arr[i]];
        
//         for(auto j: v){
//             mini = min(mini,1 + solve(j,arr,vis,mp));
//         }
        
//         if(i+1 < n){
//             mini = min(mini,1+solve(i+1,arr,vis,mp));
//         }
//         if(i-1 >= 0){
//             mini = min(mini,1+solve(i-1,arr,vis,mp));
//         }
        
//         vis[i] = 0;
        
//         return mini;
//     }
    
    int minJumps(vector<int>& arr) {
        
        int n = arr.size();

        map<int,vector<int>>mp;

        for(int i=0;i<n;i++){
            mp[arr[i]].push_back(i);
        }
        vector<int>vis(n,0);

        int ans=n;
        queue<pair<int,int>>q;
        q.push({0,0});

        while(!q.empty()){
            auto x = q.front();
            q.pop();

            int idx = x.first;
            int steps = x.second;

            if(idx == n-1){
                return steps;
            }

            vis[idx] = 1;
            if(idx+1 < n && !vis[idx+1]){
                q.push({idx+1,steps+1});
            }
            if(idx-1 >= 0 && !vis[idx-1]){
                q.push({idx-1,steps+1});
            }

            for(auto it: mp[arr[idx]]){
                
                if(!vis[it])
                q.push({it,steps+1});
                
            }

            mp.erase(arr[idx]);
        }

        return -1;
    }
};