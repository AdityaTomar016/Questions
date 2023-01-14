class DisjointSet{
    public: 
    
    vector<int>par;
    vector<int>size;

    DisjointSet(){
        par.resize(26+1);
        size.resize(26+1,1);

        for(int i=0;i<26;i++){
            par[i] = i;
        }
    }

    int findpar(int u){
        if(u == par[u]){
            return u;
        }

        return par[u] = findpar(par[u]);
    }

    void unionbysz(int u,int v){
        u = findpar(u);
        v = findpar(v);

        if(u == v) return;

        if(u > v){
            par[u] = v;
        }
        else{
            par[v] = u;
        }
    }
};
class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        
        DisjointSet d;
        
        for(int i=0;i<s1.size();i++){
            d.unionbysz(s1[i]-'a',s2[i]-'a');
        }
        
        string res="";
        for(auto i: baseStr){
            res += (d.findpar(i-'a') + 'a');
        }
        
        return res;
    }
};