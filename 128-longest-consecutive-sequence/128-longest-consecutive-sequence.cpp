class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        set<int>st;
        
        for(int i=0;i<nums.size();i++){
            st.insert(nums[i]);
        }
        
        int curr=1,mx=0;
        
        for(auto i: st){
            if(st.find(i+1)!=st.end()){
                curr++;
            }
            else{
                mx = max(mx,curr);
                curr=1;
            }
        }
        
        return mx;
    }
};