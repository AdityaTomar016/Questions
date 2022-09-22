class Solution {
public:
    string reverseWords(string s) {
        
        int j=0,size=0;
        
        for(int i=0;i<s.size();i++){
            
            if(isspace(s[i])){
                
                reverse(s.begin()+j,s.begin()+i);
                j = i+1;

            }

        }
        
        
        reverse(s.begin()+j,s.end());

        
//         s = "";
        
//         for(auto i: v){
//             s += i;
//         }
        
        return s;
    }
};

// whenever we encounter a " " reverse substr(" ", size);