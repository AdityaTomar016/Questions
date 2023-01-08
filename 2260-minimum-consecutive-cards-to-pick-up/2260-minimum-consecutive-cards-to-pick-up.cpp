class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        
        int n = cards.size();
        
        map<int,int>mp;
        int i=0,j=0;
        int ans=INT_MAX;
        
        while(j < n){
            
            int temp = cards[j];
            mp[temp]++;
            
            while(mp[temp] > 1){

                ans = min(ans,j-i+1);
                
                mp[cards[i]]--;
                i++;
            }
            
            
            j++;
        }
        
        
        if(ans == INT_MAX)  return -1;
        return ans;
    }
};