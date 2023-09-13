//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    string toposort(int i,vector<int>adj[],int n){
        vector<int>indegree(n);
        
        for(int i=0;i<n;i++){
            for(auto j: adj[i]){
                indegree[j]++;
            }
        }
        
        queue<int>q;
        
        for(int i=0;i<n;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        string res="";
        
        while(!q.empty()){
            auto x = q.front();
            q.pop();
            
            res += (x + 'a');
            for(auto it: adj[x]){
                indegree[it]--;
                
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }
        
        return res;
    }
    string findOrder(string dict[], int N, int K) {
        
        vector<int>adj[K];
        
        for(int i=0;i<N-1;i++){
            string u = dict[i];
            string v = dict[i+1];
            
            int sz = min(u.size(),v.size());
            
            for(int j=0;j<sz;j++){
                if(u[j] != v[j]){
                    adj[u[j] - 'a'].push_back(v[j] - 'a');
                    break;
                }
            }
        }
        
        string res = toposort(0,adj,K);
        
        return res;
    }
};

//{ Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends