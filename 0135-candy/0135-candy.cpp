class Solution {
public:
    int candy(vector<int>& rating) {
        int n = rating.size();
        vector<int>left(n,1);
        vector<int>right(n,1);
        
        for(int i=1;i<n;i++){
            if(rating[i] > rating[i-1]){
                left[i] = 1 + left[i-1];
            }
            else if(rating[i] < rating[i-1]){
                left[i] = 1;
            }
            else{
                left[i] = 1;
            }
        }
        
        for(int i=n-2;i>=0;i--){
            if(rating[i] > rating[i+1]){
                right[i] = max(left[i], 1 + right[i+1]);
            }
            else if(rating[i] < rating[i+1]){
                right[i] = max(left[i],1);
            }
            else{
                right[i] = max(left[i],right[i]);
            }
        }
        
        int count=0;
        
        for(int i=0;i<n;i++){
            count += max(left[i] , right[i]);
        }
        
        return count;
    }
};