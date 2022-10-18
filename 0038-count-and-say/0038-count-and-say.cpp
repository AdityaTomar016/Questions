class Solution {
public:
    string countAndSay(int n) {
        
        if(n==0){
            return "";
        }
        string ans="1";
        
        while(--n){
            string curr="";
            
                for(int i=0;i<ans.size();i++){

                    int j=i;

                    while(i+1<ans.size() && (ans[i] == ans[i+1])){
                        i++;
                    }

                curr += to_string(i-j+1) + ans[j];
            }
            
            ans = curr;
        }
        
        
        return ans;
    }
};