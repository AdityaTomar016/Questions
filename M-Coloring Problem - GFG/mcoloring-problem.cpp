//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    
    bool isSafe(int c,int node,vector<int>& col,bool graph[101][101], int n){
        for(int k=0;k<n;k++){
            if(k != node && graph[k][node] == 1 && col[k] == c){
                return false;
            }
        }
        return true;
    }
    bool solve(int i,vector<int>&col,bool graph[101][101], int m, int n){
        if(i == n){
            return true;
        }
        
        for(int j=1;j<=m;j++){
            if(isSafe(j,i,col,graph,n)){
                col[i] = j;
                if(solve(i+1,col,graph,m,n)) return true;
                col[i] = 0;
            }
        }
        
        return false;
    }
    bool graphColoring(bool graph[101][101], int m, int n) {
        vector<int>col(n,0);
        return solve(0,col,graph,m,n);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        Solution ob;
        cout << ob.graphColoring(graph, m, n) << endl;
    }
    return 0;
}

// } Driver Code Ends