class Solution {
public:
    void solve(int idx,string s,vector<string>&arr,int &ans){
        
        set<char> st;
        
        for (auto ele : s) {
            if (st.find(ele) != st.end()) return;
            st.insert(ele);
        }
        
        if(s.size() > ans){
            ans = s.size();
        }
        
        for(int i=idx;i<arr.size();i++){
            solve(i+1,s+arr[i], arr,ans);
        }
        
    }
    int maxLength(vector<string>& arr) {
        
        string s="";
        int ans=0;
        solve(0,s,arr,ans);
        
        return ans;
    }
};