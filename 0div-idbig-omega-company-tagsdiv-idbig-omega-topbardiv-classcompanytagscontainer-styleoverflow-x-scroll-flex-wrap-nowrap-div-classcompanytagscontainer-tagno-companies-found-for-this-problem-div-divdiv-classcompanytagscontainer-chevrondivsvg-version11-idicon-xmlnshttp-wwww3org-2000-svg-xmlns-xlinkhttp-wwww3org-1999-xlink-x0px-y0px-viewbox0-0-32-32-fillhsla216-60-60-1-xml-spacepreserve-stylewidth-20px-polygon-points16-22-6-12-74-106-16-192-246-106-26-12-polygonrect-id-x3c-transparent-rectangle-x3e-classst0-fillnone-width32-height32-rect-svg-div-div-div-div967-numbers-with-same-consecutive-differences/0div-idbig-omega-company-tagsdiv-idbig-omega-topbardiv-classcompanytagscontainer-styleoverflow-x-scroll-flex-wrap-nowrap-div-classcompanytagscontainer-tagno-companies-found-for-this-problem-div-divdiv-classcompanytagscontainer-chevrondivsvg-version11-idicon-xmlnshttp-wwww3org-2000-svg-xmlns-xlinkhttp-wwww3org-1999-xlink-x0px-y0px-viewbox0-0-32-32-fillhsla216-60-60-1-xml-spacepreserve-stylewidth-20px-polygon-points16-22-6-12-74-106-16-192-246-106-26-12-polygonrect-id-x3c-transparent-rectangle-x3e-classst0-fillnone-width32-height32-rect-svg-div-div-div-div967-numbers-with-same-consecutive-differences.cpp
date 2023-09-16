class Solution {
public:
    void solve(int num,int n,int k,vector<int>&ans){
        if(n == 0){
            ans.push_back(num);
            return;
        }
        
        for(int i=0;i<=9;i++){
            int l = num%10;
            if(abs(i-l) == k){
                num = num*10 + i;
                solve(num,n-1,k,ans);
                num = num/10;
            }
        }
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int>ans;

        for(int st=1;st<=9;st++){
            solve(st,n-1,k,ans);
        }
        return ans;
    }
};