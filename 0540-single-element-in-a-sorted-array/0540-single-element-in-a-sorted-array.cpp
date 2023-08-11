class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int low = 0, high = n-1;
        
        while(low <= high){
            int mid = (low+high)/2;
            
            if(mid > 0 && nums[mid] == nums[mid-1]){
                int len = mid-low+1;
                
                if(len%2 != 0){
                    high = mid-2;
                }
                else{
                    low = mid+1;
                }
            }
            else if(mid < n-1 && nums[mid] == nums[mid+1]){
                int len = high-mid+1;
                
                if(len%2 == 0){
                    high = mid-1;
                }
                else{
                    low = mid+2;
                }
            }
            else{
                return nums[mid];
            }
        }
        return -1;
    }
};