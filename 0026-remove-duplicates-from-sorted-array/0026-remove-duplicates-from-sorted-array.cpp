class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        set<int>s;
        
        for(auto i: nums){
            s.insert(i);
        }
        
        int k=0;
        
        for(auto i: s){
            nums[k++] = i;
        }
        
        return k;
    }
};