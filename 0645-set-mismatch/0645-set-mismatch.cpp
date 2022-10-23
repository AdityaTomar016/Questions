class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        
        int n=1;
        int a=0;
        int b=0;
        
        map<int,int>mp;
        
        for(auto i: nums){
            mp[i]++;
        }
        
        for(int i=1;i<=nums.size();i++){
            
            if(mp[i] > 0){
                if(mp[i] == 2){
                    a = i;
                }
            }
            else{
                b = i;
            }
        }
        
        return {a,b};
    }
};