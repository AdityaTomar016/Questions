class Solution {
public:
    bool isRobotBounded(string ins) {
        
        int dir=1;
        int x=0,y=0;
        
        for(auto i: ins){
            
            if(i == 'G'){
                if(dir == 1){
                    y++;
                }
                else if(dir == 2){
                    x++;
                }
                else if(dir == 3){
                    y--;
                }
                else{
                    x--;
                }
            }
            else if(i == 'L'){
                if(dir == 1){
                    dir=4;
                }
                else dir--;
            }
            else if(i == 'R'){
                if(dir == 4){
                    dir=1;
                }
                else dir++;
            }
        }
        
        
        if(dir != 1){
            return true;
        }
        else if(x==0 && y==0){
            return true;
        }
        return false;
    }
};