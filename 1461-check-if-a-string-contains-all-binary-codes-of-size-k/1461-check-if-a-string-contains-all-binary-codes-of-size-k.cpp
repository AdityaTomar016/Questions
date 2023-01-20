class Solution {
public:
    bool hasAllCodes(string s, int k) {
        
        int need = pow(2,k);
        set<string>set;
        
        int i=0;
        
        while(i+k <= s.size()){
            string str = s.substr(i,k);
            
            if(set.find(str) == set.end()){
                set.insert(str);
                need--;
            }
            
            if(need == 0){
                return true;
            }
            i++;
        }
        return false;
    }
};