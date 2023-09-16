//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> singleNumber(vector<int> nums) 
    {
        int xr = 0;
        int n = nums.size();
        
        vector<int>ans;
        
        for(int i=0;i<n;i++){
            xr = xr ^ nums[i];
        }
        int rightbit = (xr)&(~(xr-1));
        int x=0,y=0;
        
        for(int i=0;i<n;i++){
            if(nums[i]&rightbit){
                x = x^nums[i];
            }
            else{
                y = y^nums[i];
            }
        }
        
        ans.push_back(min(x,y));
        ans.push_back(max(x,y));
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(2 * n + 2);
    	for(int i = 0; i < 2 * n + 2; i++)
    		cin >> v[i];
    	Solution ob;
    	vector<int > ans = ob.singleNumber(v);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}
// } Driver Code Ends