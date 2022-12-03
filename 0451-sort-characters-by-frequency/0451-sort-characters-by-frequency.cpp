class Solution {
public:
    string frequencySort(string s) {
        
        map<char,int>mp;
        
        for(auto i: s){
            mp[i]++;
        }
        
        string ans="";
        
        
        priority_queue<pair<int,char>,vector<pair<int,char>>>pq;
        
        for(auto i: mp){
            pq.push({i.second,i.first});
        }
        
        while(!pq.empty()){
            auto x = pq.top();
            pq.pop();
            int freq = x.first;
            char c = x.second;
            
            for(int i=0;i<freq;i++){
                ans += c;
            }
        }
        
        return ans;
    }
};