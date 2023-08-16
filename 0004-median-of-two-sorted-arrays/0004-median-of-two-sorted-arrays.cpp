class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        
        if(n > m){
            return findMedianSortedArrays(nums2,nums1);
        }
        if(m == 0){
            if(n%2 == 0){
                return ((nums1[n/2] + nums1[n/2 - 1])/2.0);
            }
            return nums1[n/2];
        }
        int median = (m+n+1)/2;
        
        int low = 0, high = n;
        
        while(low <= high){
            int mid = (low+high)/2;
            
            int cut1 = mid;
            int cut2 = median - cut1;
            
            int l1 = (cut1 == 0) ? INT_MIN : nums1[cut1-1];
            int l2 = (cut2 == 0) ? INT_MIN : nums2[cut2-1];
            int r1 = (cut1 == n) ? INT_MAX : nums1[cut1];
            int r2 = (cut2 == m) ? INT_MAX : nums2[cut2];
            
            if(l1 > r2){
                high = cut1-1;
            }
            else if(l2 > r1){
                low = cut1 + 1;
            }
            else{
                if((m+n)%2 != 0){
                    return max(l1,l2);
                }
                else{
                    return (max(l1,l2)+min(r1,r2))/2.0;
                }
            }
        }
        return 0;
    }
};