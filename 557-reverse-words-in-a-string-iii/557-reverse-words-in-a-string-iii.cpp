class Solution {
public:
    string reverseWords(string s) {
        
        int j=0,size=0;
        vector<string>v;
        
        for(int i=0;i<s.size();i++){
            
            if(isspace(s[i])){
                string rev = s.substr(j,size);
                reverse(rev.begin(),rev.end());
                v.push_back(rev + " ");
                j = i+1;
                size=0;
                continue;
            }
            
            size++;
        }
        
        string rev = s.substr(j);
        reverse(rev.begin(),rev.end());
        v.push_back(rev);
        
        s = "";
        
        for(auto i: v){
            s += i;
        }
        
        return s;
    }
};

// whenever we encounter a " " reverse substr(" ", size);