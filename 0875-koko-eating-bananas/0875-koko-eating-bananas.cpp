class Solution {
public:
    int isfeasible(int k,vector<int>& piles){
        int curr=0;
        for(auto i: piles){
            if(i%k == 0){
                curr += i/k;
            }
            else{
                curr += i/k + 1;
            }
        }
        return curr;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        
        if(h < piles.size()){
            return -1;
        }
        
        int low = 1, high = *max_element(piles.begin(),piles.end());
        
        while(low < high){
            int mid = (low+high)/2;
            
            if(isfeasible(mid,piles) <= h){
                high = mid;
            }
            else{
                low = mid+1;
            }
        }
        return low;
    }
};