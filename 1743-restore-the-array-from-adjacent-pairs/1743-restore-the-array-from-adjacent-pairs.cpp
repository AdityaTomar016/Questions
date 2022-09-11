class Solution {
public:
    
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        
        int n = adjacentPairs.size();
        map<int,vector<int>>adj;

        vector<int>ans;
        
        for(auto i: adjacentPairs){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        
        int first,prev,num;
        
        for(auto i: adj){
            if(i.second.size()==1){
                first = i.first;
                break;
            }
        }
        
        ans.push_back(first);
        prev = first;
        num = adj[first][0];
        ans.push_back(num);
        
        for(int i=0;i<n-1;i++){
            
            if(prev != adj[num][0]){
                ans.push_back(adj[num][0]);
                prev = num;
                num = adj[num][0];
            }
            else{
                ans.push_back(adj[num][1]);
                prev = num;
                num = adj[num][1];
            }
        }
        return ans;
    }
};