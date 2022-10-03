class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        
        int mx=0,sum=0,ans=0;
        
        for(int i=0;i<colors.size();i++){
            
            if(i>0 && colors[i] != colors[i-1]){
                
                ans += sum - mx;
                sum = 0;
                mx = 0;
                
            }
            
            sum += neededTime[i];
            mx = max(mx,neededTime[i]);
        }
        
        ans += sum - mx;
        return ans;
    }
};