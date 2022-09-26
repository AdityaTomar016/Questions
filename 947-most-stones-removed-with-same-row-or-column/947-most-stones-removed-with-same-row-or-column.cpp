class Solution {
public:
    vector<int>parent;
    
    int find(int v){
        if(v == parent[v]) return v;
        
        return parent[v] = find(parent[v]);
    }
    
    bool join(int i,int j){
        int x = find(i);
        int y = find(j);
        
        if(x == y) return false;
        
        else parent[y] = x;
        
        return true;
    }
    int removeStones(vector<vector<int>>& stones) {
        
        int n = stones.size();
        parent.resize(n);
        
        int count=0;
        
        for(int i=0;i<n;i++){
            parent[i] = i;
        }
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                
                if(stones[i][0] == stones[j][0] || 
                   stones[i][1] == stones[j][1]){
                    
                    if(join(i,j)) count++;
                }
            }
        }
        
        return count;
    }
};