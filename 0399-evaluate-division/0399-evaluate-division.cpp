class Solution {
public:
void dfs(string start,string end,unordered_map<string,double>mp,
             unordered_map<string,vector<string>>graph,double &val,                map<string,int>&vis,bool &found){
        
        vis[start]=1;
        
        if(found) return;
        
        for(auto child: graph[start]){
            
            if(!vis[child]){
                
            val *= mp[start + "->" + child];
            
            if(child==end){ 
                found=true;
                return;
            }
            
            dfs(child,end,mp,graph,val,vis,found);
            
            if(found) return;
            else
                val /= mp[start +  "->" + child];
        }
        }
        
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        
        unordered_map<string,double>mp;
        unordered_map<string,vector<string>>graph;
        
        vector<double>ans;
        
        for(int i=0;i<equations.size();i++){
            string start = equations[i][0];
            string end = equations[i][1];
            
            graph[start].push_back(end);
            graph[end].push_back(start);
            
            mp[start + "->" + end] = values[i];
            mp[end + "->" + start] = 1/values[i];
        }
        
        for(int i=0;i<queries.size();i++){
            
            string start = queries[i][0];
            string end = queries[i][1];
            
            if(graph.find(start)==graph.end() ||                                    graph.find(end)==graph.end()){
                ans.push_back(-1);
            }
            else{
                map<string,int>vis;
                bool found = false;
                double val = 1;
                
                if(start==end){
                    found = true;
                }
                else{
                    dfs(start,end,mp,graph,val,vis,found);
                }
                if(found){
                    ans.push_back(val);
                }
                else ans.push_back(-1);
            }
        }
        return ans;
    }
};