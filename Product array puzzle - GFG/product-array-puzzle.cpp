//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
       
        long long prod=1;
        bool haszero=false,multiplezero=false;
        for(auto i: nums){
            
            if(i == 0 && haszero == true){
                multiplezero=true;
            }
            else if(i == 0){
                haszero = true;
            }
            else{
                prod *= i;
            }
        }
        
        vector<long long>res;
        
        if(multiplezero){
            res.resize(nums.size(),0);
            return res;
        }
        
        for(auto i: nums){
            if(i == 0 && haszero){
                res.push_back(prod);
            }
            else if(haszero){
                res.push_back(0);
            }
            else
            res.push_back(prod/i);
        }
        return res;
    }
};


//{ Driver Code Starts.
int main()
 {
    int t;  // number of test cases
    cin>>t;
    while(t--)
    {
        int n;  // size of the array
        cin>>n;
        vector<long long int> arr(n),vec(n);
        
        for(int i=0;i<n;i++)    // input the array
        {
            cin>>arr[i];
        }
        Solution obj;
        vec = obj.productExceptSelf(arr,n);   // function call
        
        for(int i=0;i<n;i++)    // print the output
        {
            cout << vec[i] << " ";
        }
        cout<<endl;
    }
	return 0;
}
// } Driver Code Ends