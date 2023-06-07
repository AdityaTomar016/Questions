class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        
        int count1=0,count2=0,element1 = 1e9+1,element2 = 1e9+1;
        
        for(int i=0;i<n;i++){
            if(count1 == 0 && nums[i] != element2){
                count1 = 1;
                element1 = nums[i];
            }
            else if(count2 == 0 && nums[i] != element1){
                count2 = 1;
                element2 = nums[i];
            }
            else if(nums[i] == element1){
                count1++;
            }
            else if(nums[i] == element2){
                count2++;
            }
            else{
                count1--;
                count2--;
            }
        }
        vector<int>ans;
        count1 = 0,count2 = 0;
        
        for(int i=0;i<n;i++){
            if(element1 == nums[i]) count1++;
            if(element2 == nums[i]) count2++;
        }
        
        if(count1 > n/3){
            ans.push_back(element1);
        }
        if(count2 > n/3){
            ans.push_back(element2);
        }
        
        return ans;
    }
};