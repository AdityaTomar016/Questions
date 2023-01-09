class Solution {
public:
    
    vector<int>bob;        
    int maxi = INT_MIN;
    
    void solve(int i,int arrow,int score,vector<int>&alice,vector<int>&ds){
        
        if(arrow <= 0 || i < 0){
            
            if(score > maxi){
                maxi = score;
                
                if(arrow > 0){
                    ds[0] += arrow;
                }
                bob = ds;
            }
            return;
        }
        
        if(arrow > alice[i]){
            ds[i] = alice[i] + 1;
            solve(i-1,arrow-ds[i],score+i,alice,ds);
            ds[i] = 0;
        }
        solve(i-1,arrow,score,alice,ds);
    }
    vector<int> maximumBobPoints(int arrows, vector<int>& aliceArrows) {
        
        vector<int>ds(12,0);
        solve(11,arrows,0,aliceArrows,ds);
        
        return bob;
    }
};