class Solution {
public:
    string fractionToDecimal(long n, long d) {
        
        unordered_map<int,int>mp;
        string res = "";
        
        if(n == 0){
            return "0";
        }
        
        if(n > 0 ^ d > 0){
            res += '-';
        }
        n = abs(n);
        d = abs(d);
        
        long q = n/d;
        long r = n%d;
        
        res += to_string(q);
        
        if(r == 0){
            return res;
        }
        
        res += '.';
        
        while(r){
            
            if(mp[r] > 0){
                res.insert(mp[r],"(");
                res += ')';
                break;
            }
            
            mp[r] = res.size();
            r = r*10;
            
            q = r/d;
            r = r%d;
            
            res += to_string(q);
        }
        
        return res;
    }
};