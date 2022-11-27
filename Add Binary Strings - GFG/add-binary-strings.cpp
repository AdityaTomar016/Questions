//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	string addBinary(string A, string B)
	{
	    // your code here
	    
	    int ind1 = A.length()-1;
	    int ind2 = B.length()-1;
	    string res = "";
	    int carry = 0;
	    while(ind1>=0 || ind2>=0){//loop till both the string is not covered
	        int sum = carry;
	        
	        if(ind1>=0)//check ind is in range or not
	           sum += A[ind1]-'0';
	            
	        if(ind2>=0)
	           sum += B[ind2]-'0';
	           
	        if(sum%2==0)//if sum is even 0 2 then '0' should be our ans
	            res.push_back('0');
	            
	        else res.push_back('1');//if sum is 1 3 then '1' should be our ans
	        
	        if(sum>=2)carry = 1; // if sum is more or equal than 2 then carry should be 1
	        else carry = 0;     //else carry is carry
	        
	        ind1--;ind2--;        

	    }
	    if(carry)res.push_back('1');//if carry is left then push '1';
	    
	    reverse(res.begin(),res.end()); // we get our ans in reversed order so reverse it first;
	    int ind;
	    for(ind=0;ind<res.length();ind++){
	        if(res[ind]=='1')break;
	    }
	    
	    res = res.substr(ind);
	    
	    return res;
	}
};

//{ Driver Code Starts.

int main()
{
	int t; cin >> t;
	while (t--)
	{
		string A, B; cin >> A >> B;
		Solution ob;
		cout << ob.addBinary (A, B);
		cout << "\n";
	}
}

// Contributed By: Pranay Bansal

// } Driver Code Ends