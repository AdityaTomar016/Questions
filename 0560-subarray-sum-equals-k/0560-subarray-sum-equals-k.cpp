class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        int n = nums.size();
        int sum = 0;
        vector<int>pre;
        
        for(int i=0;i<n;i++){
            sum += nums[i];
            pre.push_back(sum);
        }
        
        unordered_map<int,int>mp;
        int count = 0;
        mp[0] = 1;
        
        for(int i=0;i<n;i++){
            
            // if(pre[i] == k){
            //     count++;
            // }
            
            int sum = pre[i] - k;
            
            if(mp.find(sum) != mp.end()){
                count += mp[sum];
            }
            
            mp[pre[i]]++;
        }
        
        return count;
    }
};