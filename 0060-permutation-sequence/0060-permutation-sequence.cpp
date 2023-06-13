class Solution {
public:
    string getPermutation(int n, int k) {
        string s="";
        int num=1;
        
        for(int i=0;i<n;i++){
            s += to_string(num);
            num++;
        }
        
        for(int i=0;i<k-1;i++){
            next_permutation(s.begin(),s.end());
        }
        
        return s;
    }
};