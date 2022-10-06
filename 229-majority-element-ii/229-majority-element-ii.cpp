class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        int major1=-1;
        int major2=-1;
        int c1=0,c2=0;
        
        for(int i=0;i<nums.size();i++){
            
            if(major1 == nums[i]){
                c1++;
            }
            else if(major2 == nums[i]){
                c2++;
            }
            else if(c1 == 0){
                major1 = nums[i];
                c1=1;
            }
            else if(c2 == 0){
                major2 = nums[i];
                c2=1;
            }
            else{
                c1--;
                c2--;
            }
        }
        
        int count1=0,count2=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] == major1){
                count1++;
            }
            else if(nums[i] == major2){
                count2++;
            }
        }
        
        vector<int>ans;
        
        if(count1 > nums.size()/3){
            ans.push_back(major1);
        }
        if(count2 > nums.size()/3){
            ans.push_back(major2);
        }
        
        return ans;
    }
};