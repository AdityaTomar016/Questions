class Solution {
public:
    void merge(int low,int high,int mid,vector<pair<int,int>>&nums,vector<int>&ans){
        
        vector<pair<int,int>>temp(high-low+1);
        int i=low,j=mid+1,k=0;
        int smaller=0;
        
        while(i<=mid && j<=high){
            if(nums[i].first <= nums[j].first){
                ans[nums[i].second] += smaller;
                temp[k++] = nums[i++];
            }
            else{
                smaller++;
                temp[k++] = nums[j++];
            }
        }
        while(i <= mid){
            ans[nums[i].second] += smaller;
            temp[k++] = nums[i++];
        }
        while(j <= high){
            temp[k++] = nums[j++];
        }
        
        i = low,k = 0;
        while(i <= high){
            nums[i++] = temp[k++];
        }
    }
    void mergesort(int low,int high,vector<pair<int,int>>&nums,vector<int>&ans){
        if(low < high){
            int mid = (low+high)/2;
            mergesort(low,mid,nums,ans);
            mergesort(mid+1,high,nums,ans);
            merge(low,high,mid,nums,ans);
        }
    }
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int,int>>v(n);
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            v[i] = {nums[i],i};
        }
        mergesort(0,n-1,v,ans);
        
        return ans;
    }
};