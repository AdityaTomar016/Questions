class Solution {
public:
    bool isPerfectSquare(int x){
        if (x >= 0) {
            int sr = sqrt(x);
            return (sr * sr == x);
        }
        return false;
    }
    int bulbSwitch(int n) {
        int cnt=0;
        for(int i=1;i<=n;i++){
            if(isPerfectSquare(i)) cnt++;
        }
        return cnt;
    }
};