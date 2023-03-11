class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int>mp;
        
        for(int i = 0;i<nums.size();i++){
            mp[nums[i]] = i;
        }
        vector<int> ans;
        for(int i = 0;i<nums.size();i++){
            if(mp.find(target-nums[i]) != mp.end()){
                int j = mp[target-nums[i]];
                if(i != j){
                    ans = {i,j};
                    break;
                }
               
            }
        }
        return ans;
    }
};