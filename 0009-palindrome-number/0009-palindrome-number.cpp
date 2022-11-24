class Solution {
public:
    bool isPalindrome(int x) {
        
        if(x < 0) return false;
        
        long long original = x;
        long long rev = 0;
        while(x>0){
            rev = x%10 + rev*10;
            x= x/10;
        }
        return rev==original ? true : false;
    }
};