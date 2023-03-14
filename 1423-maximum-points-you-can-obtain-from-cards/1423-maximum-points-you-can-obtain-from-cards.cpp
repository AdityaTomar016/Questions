class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int sum = 0;
        vector<int>pre,suff;
        pre.push_back(0);
        suff.push_back(0);
        
        for(int i=0;i<n;i++){
            sum += cardPoints[i];
            pre.push_back(sum);
        }
        sum = 0;
        
        for(int i=n-1;i>=0;i--){
            sum += cardPoints[i];
            suff.push_back(sum);
        }
        
        int maxi = INT_MIN;
    
        int i=k,j=0;
        int curr;
        
        while(j <= k){
            curr = pre[i] + suff[j];
            maxi = max(maxi,curr);
            i--;j++;
        }
        return maxi;
    }
};