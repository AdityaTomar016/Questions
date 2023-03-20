class Solution {
public:
//     bool solve(int i,vector<int>& flowerbed, int n){
        
//         if(n == 0){
//             return true;
//         }
//         if(i >= flowerbed.size()){
//             return false;
//         }
        
//         bool take=false,nottake = false;
        
//         if(i > 0 && flowerbed[i-1] != 1 && i < n-1 && flowerbed[i+1] != 1){
//             take = solve(i+2,flowerbed,n-1);
//         }
//         nottake = solve(i+1,flowerbed,n);
        
//         return take || nottake;
//     }
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        
        int count = 0;
        for(int i=0;i<flowerbed.size();i++){
            
            if(flowerbed[i] == 0){
                
                bool left = true, right = true;
                
                if(i > 0 && flowerbed[i-1] == 1){
                    left = false;
                }
                if(i < flowerbed.size()-1 && flowerbed[i+1] == 1){
                    right = false;
                }
                
                if(left && right){
                    flowerbed[i] = 1;
                    count++;
                }
            }
            
            if(count >= n){
                return true;
            }
        }
        return count>=n;
    }
};