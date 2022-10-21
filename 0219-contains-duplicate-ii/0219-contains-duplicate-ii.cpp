class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) 
    {
       int n=nums.size();
       unordered_set<int>st;
        
        int i=0,j=0;
        
        while(j < n){
            
            if(j-i <= k){
                if(st.find(nums[j]) == st.end()){
                    st.insert(nums[j]);
                    j++;
                }
                else return true;
            }
            else{
                st.erase(nums[i]);
                i++;
            }
        }
        
        return false;
    }
};