class Solution {
public:
    int solve(int i,int j,bool turn,int sum,vector<int>&piles){
        if(i > j){
            return 0;
        }
        
        int alice=0;
        
        if(turn){
            if(piles[i] > piles[j]){
                alice += piles[i] + solve(i+1,j,0,sum-piles[i],piles);
            }
            else{
                alice += piles[j] + solve(i,j-1,0,sum-piles[j],piles);
            }
        }
        else{
            if(piles[i] > piles[j]){
                alice += solve(i,j-1,1,sum,piles);
            }
            else{
                alice += solve(i+1,j,1,sum,piles);
            }
        }
        return alice;
    }
    bool stoneGame(vector<int>& piles) {
        int sum=0;
        
        for(auto i: piles){
            sum += i;
        }
        
        int alice_total = solve(0,piles.size()-1,1,sum,piles);
        
        return alice_total > (sum - alice_total);
    }
};