class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        
        k = k % (nums.size());
        
        int n = nums.size()-1;
        vector<int>v(k);
        
        int temp = k;
        
        int i=0;
        while(temp--){
            v.push_back(nums[n-i]);
            i++;
        }
        reverse(v.begin(),v.end());
        
        temp = n;
        
        for(int i=n-k;i>=0;i--){
            nums[temp] = nums[i];
            temp--;
        }
        
        for(int i=0;i<k;i++){
            nums[i] = v[i];
        }
        
    }
};