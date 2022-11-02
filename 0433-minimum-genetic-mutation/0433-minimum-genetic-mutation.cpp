class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        
        unordered_set<string>b;
        
        unordered_set<string>vis;
        
        for(auto i: bank){
            b.insert(i);
        }
        b.insert(start);
        
        int count=0;
        
        queue<string>q;
        
       q.push(start);
        
        
        while(!q.empty()){
            int sz = q.size();
            
            for(int i=0;i<sz;i++){
                
                auto s = q.front();
                q.pop();
                
                if(s == end){
                    return count;
                }
                
                if(vis.find(s)==vis.end()){
                    
                    vis.insert(s);
                    
                    for(int i=0;i<8;i++){
                        
                            
                            string t = s;
                            
                            t[i] = 'A';
                            if(b.find(t)!=b.end())
                            q.push(t);
                            
                            t[i] = 'C';
                            if(b.find(t)!=b.end())
                            q.push(t);
                            
                            t[i] = 'G';
                            if(b.find(t)!=b.end())
                            q.push(t);
                                
                            t[i] = 'T';
                            if(b.find(t)!=b.end())
                            q.push(t);
                            
                        }
                        
                    }
                }
            
            count++;
            }
        
        
        return -1;
    }
};