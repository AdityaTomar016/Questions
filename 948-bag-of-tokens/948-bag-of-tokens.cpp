class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        
        int n = tokens.size();
        
        sort(tokens.begin(),tokens.end());
        
        int score = 0,ans=0;
        
        if(tokens.size()==1){
            if(power >= tokens[0]){
                return 1;
            }
            else return 0;
        }
        
        int i = 0,j = n-1;
        
        while(i<=j){
            if(power >= tokens[i]){
                score++;
                power -= tokens[i++];
                ans = max(ans,score);
            }
            else if(score>0){
                power += tokens[j--];
                score--;
            }
            else break;
        }
        return ans;
    }
};

//score = 0
//token = 71 
//power = 83