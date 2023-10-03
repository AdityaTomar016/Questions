class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        
        unordered_map<int,int>mp;
        for(auto i: nums){
            mp[i]++;
        }
        
        int res = 0;
        
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]--;
            if(mp[nums[i]] > 0){
                res += mp[nums[i]];
            }
        }
        
        return res;
    }
};