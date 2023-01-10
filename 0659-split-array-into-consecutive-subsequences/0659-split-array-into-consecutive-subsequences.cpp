class Solution {
public:
    bool isPossible(vector<int>& nums) {
        
        map<int,int>mp;
        
        for(auto i: nums){
            mp[i]++;
        }
        
        for(auto i: nums){
            
            int freq = mp[i];
            int curr=i;
            int count=0;
            
            if(freq == 0) continue;
            
            while(mp[curr] >= freq){
                freq = mp[curr];
                mp[curr]--;
                count++;
                curr++;
            }
            
            
            if(count < 3){
                return false;
            }
        }
        
        return true;
    }
};