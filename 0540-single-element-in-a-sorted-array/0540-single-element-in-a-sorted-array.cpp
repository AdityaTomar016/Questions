class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int low = 0, high = n-1;
        
        while(low<=high){
            int mid = (low+high)/2;
            
            if(mid>0 && nums[mid] == nums[mid-1]){
                if((mid-1-low)%2 == 0){
                    low = mid+1;
                }
                else{
                    high = mid-2;
                }
            }
            else if(mid < n-1 && nums[mid] == nums[mid+1]){
                if((n-1-mid-1)%2 == 0){
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