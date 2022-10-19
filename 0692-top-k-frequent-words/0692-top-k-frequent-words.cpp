class myComparator {
  public:
    bool operator() (const pair<int,string>&p1, const pair<int,string>&p2) {
        
      if(p1.first == p2.first) return p1.second > p2.second;
      
      return p1.first < p2.first;
    }
};

class Solution {
public:
    
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string,int>mp;
        
        for(auto i: words){
            mp[i]++;
        }
        
        priority_queue<pair<int,string>,vector<pair<int,string>>,myComparator>pq;
        
        for(auto i: mp){
            pq.push({i.second,i.first});
            
            
        }
        
        vector<string>ans;
        
        for(int i=0;i<k;i++){
            auto x = pq.top();
            pq.pop();
            
            ans.push_back(x.second);
        }
        
        
        return ans;
    }
};