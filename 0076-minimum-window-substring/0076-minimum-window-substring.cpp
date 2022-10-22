class Solution {
public:
    string minWindow(string s, string t) {
        
        if(s.size()==0 || t.size()==0) return "";
        
        vector<int>mp(128,0);
        
        for(auto c: t){
            mp[c]++;
        }
        
        int end=0;    //end pointer of currently iterating string
        int start=0;  //start pointer of currently iterating string
        int head=0;   //start pointer of smallest string containing all elements of t ever found
        int min_len=INT_MAX;
        int req = t.size();
        
        while(start < s.size() && end <= s.size()){
            
            // still chararacters needed to cover all elements of t
            if(req > 0){
                
                if(end == s.size()) break;
                
                mp[s[end]]--;
                
                if(mp[s[end]] >= 0){
                    req--;
                }
                end++;
            }
            else{
                if(end-start < min_len){
                    min_len = end-start;
                    head = start;
                }
                
                mp[s[start]]++;
                
                if(mp[s[start]] > 0){  //if the current char was one from t so if we are moving forward we will require that char in future 
                    req++;
                }
                start++;
            }
        }
        
        if(min_len == INT_MAX)
            return "";
        
        
        return s.substr(head,min_len);
    }
};