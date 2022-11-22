//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int countTriplets(vector<int>nums){
	    
	    int ans=0;
	    int n = nums.size();
	    
	    for(int j=1;j<n-1;j++){
	        
	        int left=0,right=0;
	        
	        for(int i=j-1;i>=0;i--){
	            if(nums[j] > nums[i]) left++;
	        }
	        for(int k=j+1;k<n;k++){
	            if(nums[k] > nums[j]) right++;
	        }
	        
	        ans += left * right;
	    }
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
		vector<int>nums(n);
		for(int i = 0; i < n; i++)cin >> nums[i];
		Solution ob;
		int ans = ob.countTriplets(nums);
		cout << ans << "\n";
	}  
	return 0;
}
// } Driver Code Ends