class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2, int k) {
        
        vector<long long>up,low;
        
        if(k == 0){
            if(nums1 == nums2)
            return 0;
            
            return -1;
        }
        
        for(int i=0;i<nums1.size();i++){
            
            long long diff = nums1[i] - nums2[i];
            
            if(diff == 0) continue;
            
            if(diff%k != 0){
                return -1;
            }
            
            if(diff < 0){
                low.push_back(abs(diff));
            }
            else{
                up.push_back(diff);
            }
        }
        
        long long  sum1=0,sum2=0;
        
        for(auto i: up){
            sum1 += i;
        }
        for(auto i: low){
            sum2 += i;
        }
        
        if(sum1%k != 0 || sum2%k != 0){
            return -1;
        }
        
        if(sum1 == sum2){
            return sum1/k;
        }
        return -1;
    }
};