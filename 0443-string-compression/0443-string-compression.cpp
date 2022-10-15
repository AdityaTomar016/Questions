class Solution {
public:
    int compress(vector<char>& chars) {
        
        int len=1;
        string s="";
        
        for(int i=0;i<chars.size();i++){
            
            while(i<chars.size()-1 && chars[i]==chars[i+1]){
                i++;
                len++;
            }
            
            s += chars[i];
            
            if(len==1){
                continue;
            }
        
            s += to_string(len);
            len=1;
        
        }
        chars.clear();
        
        for(auto i: s){
            chars.push_back(i);
        }
        
        return chars.size();
    }
};