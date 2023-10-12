class Solution {
public:
    bool ispossible(int day,vector<int>&bloomDay,int m,int k){
        int i=0;
        int bouqs=0;
        
        while(i<bloomDay.size()){
            int count=0;
            while(i<bloomDay.size() && bloomDay[i] <= day){
                count++;
                i++;
                
                if(count == k){
                    break;
                }
            }
            if(count == k){
                bouqs++;
                continue;
            }
            
            i++;
        }
        if(bouqs >= m){
            return true;
        }
        
        return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        
        int low=1,high=*max_element(bloomDay.begin(),bloomDay.end());
        int ans = -1;
        while(low <= high){
            int mid = (low+high)/2;
            
            if(ispossible(mid,bloomDay,m,k)){
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