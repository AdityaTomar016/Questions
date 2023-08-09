//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    void solve(int i,int j,int n,vector<vector<int>> &mat,string s,vector<string> &ans){
        if(i<0 || j<0 || i>=n || j>=n || mat[i][j] == 0 || mat[i][j] == 2){
            return;
        }
        if(i == n-1 && j == n-1){
            ans.push_back(s);
            return;
        }
        
        mat[i][j] = 2;
        
        solve(i+1,j,n,mat,s+'D',ans);
        solve(i-1,j,n,mat,s+'U',ans);
        solve(i,j+1,n,mat,s+'R',ans);
        solve(i,j-1,n,mat,s+'L',ans);
        
        mat[i][j] = 1;
    }
    vector<string> findPath(vector<vector<int>> &mat, int n) {
        vector<string>ans;
        string s = "";
        
        solve(0,0,n,mat,s,ans);
        return ans;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends