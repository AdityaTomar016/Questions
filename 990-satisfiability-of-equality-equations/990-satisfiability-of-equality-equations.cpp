class Solution {
public:
    int parent[26];
    
    int find(int v){
        if(v == parent[v]) return v;
        
        return parent[v] = find(parent[v]);
    }
    bool equationsPossible(vector<string>& equations) {
        
        for(int i=0;i<26;i++){
            parent[i] = i;
        }
        
        for(auto e: equations){
            if(e[1] == '='){
                parent[find(e[0]-'a')] = find(e[3]-'a');
            }
        }
        for(auto e: equations){
            if(e[1] == '!' && 
                    find(e[0]-'a') == find(e[3]-'a')){
                return false;
            }
        }
        return true;
    }
};