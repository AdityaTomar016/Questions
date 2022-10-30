class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        int n = nums.size();
        vector<int>ans;
        
        // if(n <= k){
        //     int m = *max_element(nums.begin(),nums.end());
        //     return {m};
        // }
        list<int>l;
        
        for(int i=0;i<n;i++){
            
            if(!l.empty() && l.front() == i-k){
                l.pop_front();
            }
            
            while(!l.empty() && nums[i] > nums[l.back()]){
                l.pop_back();
            }
            
            l.push_back(i);
            
            if(i>=k-1)
            ans.push_back(nums[l.front()]);
        }
        
        return ans;
    }
};