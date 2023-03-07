class Solution {
public:
    long long int isallowed(vector<int>&a , long long int givenTime)
    {
        long long int totalTrips = 0;
        for(auto x : a)
        {
            // convert it to long long int 
            long long int val = x;
			
            totalTrips += (givenTime / val);
        }
        return totalTrips;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        
        long long int low = 1,high = 1e14;
        
        while(low < high){
            long long int mid = low + (high-low)/2;
            
            if(isallowed(time,mid) >= totalTrips){
                high = mid;
            }
            else{
                low = mid+1;
            }
        }
        return low;
    }
};