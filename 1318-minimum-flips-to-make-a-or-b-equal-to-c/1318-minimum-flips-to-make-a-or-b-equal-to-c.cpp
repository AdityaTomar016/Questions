class Solution {
public:
    
    void check_setBits(int n,vector<int>&v){
        int bitpos = 0;
        
        while(n > 0){
            if(n&1){
                v[bitpos] = 1;
            }
            
            n = n>>1;
            bitpos++;
        }
    }
    int minFlips(int a, int b, int c) {
        vector<int>a_bits(32),b_bits(32),c_bits(32);
        
        check_setBits(a,a_bits);
        check_setBits(b,b_bits);
        check_setBits(c,c_bits);
        
        int ans=0;
        
        for(int i=0;i<32;i++){
            if(c_bits[i] == 1){
                if(a_bits[i]==0 && b_bits[i]==0){
                    ans += 1;
                }
            }
            else if(c_bits[i] == 0){
                if(a_bits[i]==1 && b_bits[i]==1){
                    ans += 2;
                }
                else if(a_bits[i]==1 || b_bits[i]==1){
                    ans += 1;
                }
            }
        }
        return ans;
    }
};