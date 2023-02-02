class Solution {
public:
    unordered_map<char,int>mp;
    
    bool check(string s1,string s2){
        int n = s1.size();
        int m = s2.size();
        
        int i=0,j=0;
        
        while(i<n && j<m){
            
            if(mp[s1[i]] < mp[s2[j]]){
                return true;
            }
            else if(mp[s1[i]] > mp[s2[j]]){
                return false;
            }
            
            i++;
            j++;
        }
        
        if(n <= m){
            return true;
        }

        return false;
    }
    bool isAlienSorted(vector<string>& words, string order) {

        for(int i=0;i<26;i++){
            mp[order[i]] = i;
        }
        
        int n = words.size();
        
        for(int i=0;i<n-1;i++){
            string s1 = words[i];
            string s2 = words[i+1];
            
            if(check(s1,s2) == false){
                return false;
            }
        }
        return true;
    }
};