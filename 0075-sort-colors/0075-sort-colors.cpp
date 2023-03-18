class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        map<int,int>mp;
        
        for(auto i: nums){
            mp[i]++;
        }
        
        int st = 0;
        
        for(auto i: mp){
            int num = i.first;
            int count = i.second;
            
            for(int j=0;j<count;j++){
                nums[st] = num;
                st++;
            }
        }
    }
};