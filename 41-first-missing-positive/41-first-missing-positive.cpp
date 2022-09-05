class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        unordered_set<int>s;
        
        for(auto i: nums){
            s.insert(i);
        }
        
        int i=1;
        int ans = 0;
        while(true){
            if(s.find(i)==s.end()){
                ans = i;
                break;
            }
            i++;
        }
        return ans;
    }
};