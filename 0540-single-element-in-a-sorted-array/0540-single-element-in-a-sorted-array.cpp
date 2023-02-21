class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        
        int n = nums.size();
        int left = 0, right = n-1;
        int ans=0;
        
        while(left <= right){
            
            int mid = (left+right)/2;
            
            bool equal = (mid-left)%2 == 0;
            
            if(mid > 0 && nums[mid] == nums[mid-1]){
                if(equal){
                    right = mid-2;
                }
                else{
                    left = mid+1;
                }
            }
            else if(mid+1 < n && nums[mid] == nums[mid+1]){
                if(equal){
                    left = mid+2;
                }
                else{
                    right = mid-1;
                }
            }
            else{
                ans = nums[mid];
                break;
            }
        }
        
        return ans;
    }
};