class Solution {
public:
    int romanToInt(string s) {
        int sum=0;
        int n = s.size();
        
        int i=0;
        while(i<n){
            if(s[i] == 'I'){
                if(i<n-1 && s[i+1] == 'V'){
                    sum += 4;
                    i += 2;
                }
                else if(i<n-1 && s[i+1] == 'X'){
                    sum += 9;
                    i += 2;
                }
                else{
                    sum += 1;
                    i++;
                }
            }
            else if(s[i] == 'X'){
                if(i<n-1 && s[i+1] == 'L'){
                    sum += 40;
                    i += 2;
                }
                else if(i<n-1 && s[i+1] == 'C'){
                    sum += 90;
                    i += 2;
                }
                else{
                    sum += 10;
                    i++;
                }
            }
            else if(s[i] == 'C'){
                if(i<n-1 && s[i+1] == 'D'){
                    sum += 400;
                    i += 2;
                }
                else if(i<n-1 && s[i+1] == 'M'){
                    sum += 900;
                    i += 2;
                }
                else{
                    sum += 100;
                    i++;
                }
            }
            else if(s[i] == 'V'){
                sum += 5;
                i++;
            }
            else if(s[i] == 'X'){
                sum += 10;
                i++;
            }
            else if(s[i] == 'L'){
                sum += 50;
                i++;
            }
            else if(s[i] == 'C'){
                sum += 100;
                i++;
            }
            else if(s[i] == 'D'){
                sum += 500;
                i++;
            }
            else if(s[i] == 'M'){
                sum += 1000;
                i++;
            }
        }
        
        return sum;
    }
};