class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1=0,cnt2=0,maj1 = 1e9+1,maj2 = 1e9+1;
        
        for(int i=0;i<nums.size();i++){
            if(cnt1 == 0 && nums[i] != maj2){
                maj1 = nums[i];
                cnt1 = 1;
            }
            else if(cnt2 == 0 && nums[i] != maj1){
                maj2 = nums[i];
                cnt2 = 1;
            }
            else if(maj1 == nums[i]) cnt1++;
            else if(maj2 == nums[i]) cnt2++;
            else{
                cnt1--;
                cnt2--;
            }
        }
        
        vector<int>ans;
        cnt1 = 0, cnt2 = 0;
        
        for(int i=0;i<nums.size();i++){
            if(nums[i] == maj1) cnt1++;
            if(nums[i] == maj2) cnt2++;
        }
        
        if(cnt1 > nums.size()/3){
            ans.push_back(maj1);
        }
        if(cnt2 > nums.size()/3){
            ans.push_back(maj2);
        }
        return ans;
    }
};