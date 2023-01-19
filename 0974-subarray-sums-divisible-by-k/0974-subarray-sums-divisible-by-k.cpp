class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        
        unordered_map<int,int>mp;
        
        int curr_sum = 0;
        int ans=0;
        
        mp[0] = 1;
        
        for(int i=0;i<nums.size();i++){
            
            curr_sum += nums[i];
            
            int rem = curr_sum%k;
            
            if(rem < 0){
                rem += k;
            }
            
            if(mp.find(rem) != mp.end()){
                ans += mp[rem];
            }
            mp[rem]++;
        }
        
        return ans;
    }
};