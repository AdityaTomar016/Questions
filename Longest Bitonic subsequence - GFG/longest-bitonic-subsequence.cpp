//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int LongestBitonicSequence(vector<int>arr)
	{
	   int n = arr.size();
        vector<int>dp1(n,1);
     
        
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(arr[j] < arr[i] && 1+dp1[j] > dp1[i]){
                    dp1[i] = 1 + dp1[j];
                }
            }
        }
        
        vector<int>dp2(n,1);
        int maxi=0;
        
        for(int i=n-1;i>=0;i--){
            for(int j=n-1;j>i;j--){
                if(arr[j] < arr[i] && 1+dp2[j] > dp2[i]){
                    dp2[i] = 1 + dp2[j];
                }
            }
            
            maxi = max(dp1[i] + dp2[i] - 1, maxi);
        }
        
        return maxi;
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
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution ob;
		int ans = ob.LongestBitonicSequence(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends