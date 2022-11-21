//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	
	void solve(int num,int target, vector<int>&ds,vector<vector<int>>&ans){
	    
	    if(target == 0){
	        ans.push_back(ds);
	        return;
	    }
	    
	    if(num == 0) return;
	    
	    if(target >= num){
	        ds.push_back(num);
	        solve(num,target - num,ds,ans);
	        ds.pop_back();
	    }
	    
	    solve(num-1,target,ds,ans);
	}
    vector<vector<int>> UniquePartitions(int n) {
        
        vector<vector<int>>ans;
        vector<int>ds;
        
        solve(n,n,ds,ans);
        
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		vector<vector<int>> ans = ob.UniquePartitions(n);
    	for(auto i : ans)
    		for(auto j: i)
    			cout << j <<" ";
    	cout << "\n";
	}  
	return 0;
}
// } Driver Code Ends