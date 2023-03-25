class Solution {
public:
    int minMoves(vector<int>& nums) {
        
       int mini = *min_element(nums.begin(),nums.end());
        int ans = 0;
        set<int>s;
        
        // for(auto i: nums){
        //     s.insert(i);
        // }
        
        for(auto i: nums){
            ans += i-mini;
        }
    
        return ans;
    }
};