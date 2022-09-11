class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        
        int sz = tasks.size();
        unordered_map<char,int>mp;
        int mx_cnt = 0;
        for(auto i: tasks){
            mp[i]++;
            
            if(mp[i] > mx_cnt){
                mx_cnt = mp[i];
            }
        }
        
        int ans = (mx_cnt-1)*(n+1);
        
        for(auto i: mp){
            if(i.second == mx_cnt) ans++;
        }
        
        return max(sz,ans);
    }
};