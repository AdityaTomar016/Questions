class Solution {
public:
    void dfs(string start,string end,double &value,unordered_map<string,vector<string>>mp,unordered_map<string,double>val,map<string,bool>vis,bool &found){
        
        vis[start] = true;
        if(found) return;
        
        
        
        for(auto child: mp[start]){
            if(!vis[child]){
                value *= val[start + "->" + child];
                
                if(child == end){
                    found = true;
                    return;
                }
                
                dfs(child,end,value,mp,val,vis,found);
                
                if(found) return;
                else{
                    value /= val[start + "->" + child];
                }
            }
        }
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string,double>val;
        unordered_map<string,vector<string>>mp;
        vector<double>ans;
        
        for(int i=0;i<equations.size();i++){
            string start = equations[i][0];
            string end = equations[i][1];
            
            mp[start].push_back(end);
            mp[end].push_back(start);
            
            val[start + "->" + end] = values[i];
            val[end + "->" + start] = 1/values[i];
        }
        
        for(int i=0;i<queries.size();i++){
            string start = queries[i][0];
            string end = queries[i][1];
            
            if(mp.find(start) == mp.end() || mp.find(end) == mp.end()){
                ans.push_back(-1);
            }
            else{
                map<string,bool>vis;
                
                bool found = false;
                double value = 1;
                
                if(start == end){
                    found = true;
                }
                else{
                    dfs(start,end,value,mp,val,vis,found);
                }
                
                if(found){
                    ans.push_back(value);
                }
                else{
                    ans.push_back(-1);
                }
            }
        }
        return ans;
    }
};