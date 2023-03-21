class Solution {
public:
    long long perfectsquare(long long n){
        long long ans = (int)floor(sqrt(n));
        return ans;
    }
    long long solve(vector<int>& ranks,long long mid){
        
        long long total = 0;
        
        for(int i=0;i<ranks.size();i++){
            int cars = sqrt(1.0 * mid/ranks[i]);
            total += cars;
        }
        
        return total;
    }
    long long repairCars(vector<int>& ranks, long long cars) {
        long long low=1,high;
        
        high = (*min_element(ranks.begin(),ranks.end())*cars*cars);
        
        while(low < high){
            
            long long mid = (low+high)/2;
            
            if(solve(ranks,mid) >= cars){
                high = mid;
            }                                                                           
            else{
                low = mid+1;
            }
        }
        return low;
    }
};