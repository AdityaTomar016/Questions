class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=m-1,j=n-1,last=m+n-1;
        
        while(i>=0 && j>=0){
            if(nums2[j] < nums1[i]){
                nums1[last] = nums1[i];
                last--;
                i--;
            }
            else{
                nums1[last] = nums2[j];
                last--;
                j--;
            }
        }
        
        while(i>=0){
            nums1[last] = nums1[i];
            last--;
            i--;
        }
        while(j>=0){
            nums1[last] = nums2[j];
            last--;
            j--;
        }
    }
};