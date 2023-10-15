class Solution {
public:
    bool ispossible(int mid,int n,vector<int>&piles,int h){
        long long hours=0;
        
        for(int i=0;i<n;i++){
            if(piles[i] < mid){
                hours++;
            }
            else{
                if(piles[i]%mid == 0){
                    hours += piles[i]/mid;
                }
                else{
                    hours += piles[i]/mid + 1;
                }
            }
        }
        
        return hours <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        
        int low = 1, high = *max_element(piles.begin(),piles.end());
        int ans = -1;
        
        while(low <= high){
            int mid = (low+high)/2;
            
            if(ispossible(mid,n,piles,h)){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};