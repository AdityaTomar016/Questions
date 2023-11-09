class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int>mp;
        mp[0] = 1;
        
        int curr=0,res=0;
        
        for(int i=0;i<nums.size();i++){
            curr += nums[i];
            
            if(mp.find(curr-goal) != mp.end()){
                res += mp[curr-goal];
            }
            
            mp[curr]++;
        }
        
        return res;
    }
};