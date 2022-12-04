class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) 
    {
        int n = nums.size();
        long long total = 0;
        long long curr = 0;
        for(auto it : nums) total += it;
        
        long long res;
        long long temp = INT_MAX;
        
        for(int i=0;i<n;i++)
        {
            curr += nums[i];                          
            long long avg1 = curr/(i+1);                  
            
    
            if(i==n-1)
            {
                if(avg1 < temp) 
                    return n-1;
                else 
                    break;
            }
            
            long long avg2 = (total-curr)/(n-i-1);        
            

            if(abs(avg1-avg2) < temp)
            {
                temp = abs(avg1-avg2);
                res = i;
            }
        }
        
        return res;
    }
};