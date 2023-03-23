//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string t)
    {
        int n  =s.size();
        int m = t.size();
        
        unordered_map<char,int>mp;
        set<char>set;
        
        for(auto i: t){
            mp[i]++;
            set.insert(i);
        }
        
        int i=0,j=0,mini = INT_MAX;
        int st=0;
        int req = t.size();
        
        while(i < n && j <= n){
            
            if(req > 0){
                
                if(j == n){
                    break;
                }
                
                if(set.find(s[j]) != set.end()){
                    mp[s[j]]--;
                    
                    if(mp[s[j]] >= 0){
                        req--;
                    }
                }
               
                j++;
            }
            else{
                if(mini > j-i){
                    mini = j-i;
                    st = i;
                }
                
                if(set.find(s[i]) != set.end()){
                    mp[s[i]]++;
                }
                
                if(mp[s[i]] > 0){
                    req++;
                }
                
                i++;
            }
        }
        
        if(mini == INT_MAX){
            return "-1";
        }
        
        return s.substr(st,mini);
    }
};

//{ Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends