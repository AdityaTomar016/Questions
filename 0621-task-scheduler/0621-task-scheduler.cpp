class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        
        map<char,int>mp;
        int max_ch = 1;
        
        for(auto ch: tasks){
            mp[ch]++;
            
            max_ch = max(max_ch,mp[ch]);
        }
        
        int ans = (max_ch-1)*(n+1);
        
        for(auto it: mp){
            if(it.second == max_ch){
                ans++;
            }
        }
        
        return max((int)tasks.size(), ans);
    }
};