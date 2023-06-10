class Solution {
public:
    long long ispossible(int target,int n,int index){
        long long res=0;
        
        long long stNum = max(target-index,0);
        res += (long long)(stNum + target)*(target - stNum + 1)/2;
        
        long long endNum = max(target-(n-index-1), 0);
        res += (long long)(endNum + target)*(target - endNum + 1)/2;
        
        return res-target;
    }
    int maxValue(int n, int index, int maxSum) {
        maxSum -= n;
        int low = 0,high = maxSum;
        
        while(low<high){
            int mid = (low+high+1)/2;
            
            if(ispossible(mid,n,index) <= maxSum){
                low = mid;
            }
            else{
                high = mid-1;
            }
        }
        
        return low+1;
    }
};