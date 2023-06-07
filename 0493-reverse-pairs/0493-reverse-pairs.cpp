class Solution {
public:
    void merge(int low,int mid,int high,vector<int>&nums){
        int l=low,r=mid+1,k=0;
        
        vector<int>temp(high-low+1);

        
        while(l<=mid && r<=high){
            if(nums[l] <= nums[r]){
                temp[k++] = nums[l++];
            }
            else{
                temp[k++] = nums[r++];
            }
        }
        
        while(l<=mid){
            temp[k++] = nums[l++];
        }
        while(r<=high){
            temp[k++] = nums[r++];
        }
        k=0;
        for(int i=low;i<=high;i++){
            nums[i] = temp[k++];
        }

    }
    long long mergeSort(int low,int high,vector<int>&nums){
        long long count=0;
        if(low < high){
            int mid = (low+high)/2;
            count += mergeSort(low,mid,nums);
            count += mergeSort(mid+1,high,nums);
            
            int i=low,j=mid+1;
            while(i<=mid && j<=high){
                if(nums[i] > 2*(long long)nums[j]){
                    count += mid-i+1;
                    j++;
                }
                else i++;
            }
            
            merge(low,mid,high,nums);
        }
        
        return count;
    }
    int reversePairs(vector<int>& nums) {
        
        int i=0,j=nums.size()-1;
        
        return mergeSort(i,j,nums);
    }
};