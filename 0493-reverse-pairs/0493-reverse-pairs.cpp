class Solution {
public:
    void merge(int low,int mid,int high,vector<int>&nums){
        int n1 = mid-low+1;
        int n2 = high-mid;
        
        vector<int>a(n1),b(n2);
        
        for(int i=0;i<n1;i++){
            a[i] = nums[i+low];
        }
        for(int j=0;j<n2;j++){
            b[j] = nums[j+mid+1];
        }
        int i=0,j=0,k=low;
        
        while(i<n1 && j<n2){
            if(a[i] > b[j]){
                nums[k++] = b[j++];
            }
            else{
                nums[k++] = a[i++];
            }
        }
        
        while(i<n1){
            nums[k++] = a[i++];
        }
        while(j<n2){
            nums[k++] = b[j++];
        }
    }
    long long mergesort(int low,int high,vector<int>&nums){
        long long count = 0;
        
        if(low < high){
            int mid = (low+high)/2;
            count += mergesort(low,mid,nums);
            count += mergesort(mid+1,high,nums);
            
            int i=low,j=mid+1;
            
            while(i<=mid && j<=high){
                if(nums[i] > 2*(long)nums[j]){
                    count += mid-i+1;
                    j++;
                }
                else{
                    i++;
                }
            }
            
            merge(low,mid,high,nums);
        }
        return count;
    }
    int reversePairs(vector<int>& nums) {
        return mergesort(0,nums.size()-1,nums);
    }
};