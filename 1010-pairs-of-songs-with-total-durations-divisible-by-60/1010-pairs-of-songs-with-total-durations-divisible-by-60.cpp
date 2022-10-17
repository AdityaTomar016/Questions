class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        
        int ans=0;
        vector<int>v(60,0);
        
        for(int i=0;i<time.size();i++){
            
            int x = time[i]%60;
            
            if(x == 0){
                ans += v[x];
            }
            else{
                ans += v[60 - x];
            }
            
            v[x]++;
        }
        return ans;
    }
};