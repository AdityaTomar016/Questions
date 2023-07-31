class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        unordered_set<int>st;
        
        for(auto i: nums){
            st.insert(i);
        }
        
        int maxi = 0;
        
        for(int i=0;i<nums.size();i++){
            
            if(st.find(nums[i]-1) == st.end()){
                int cnt = 1;
                int x = nums[i];

                while(st.find(x+1) != st.end()){
                    cnt++;
                    x = x+1;
                }
                maxi = max(maxi,cnt);
            }
        }
        
        return maxi;
    }
};