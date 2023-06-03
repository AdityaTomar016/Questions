//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
};


// } Driver Code Ends
/*
The structure of petrolPump is 
struct petrolPump
{
    int petrol;
    int distance;
};*/

/*You are required to complete this method*/
class Solution{
  public:
  
    int tour(petrolPump p[],int n)
    {
       int curr = 0,total = 0;
       int ans = 0;
       
       for(int i=0;i<n;i++){
           curr += p[i].petrol - p[i].distance;
           total += p[i].petrol - p[i].distance;
           
           if(curr < 0){
               curr = 0;
               ans = i+1;
           }
       }
       
       if(total < 0) return -1;
       return ans;
    }
};



//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        petrolPump p[n];
        for(int i=0;i<n;i++)
            cin>>p[i].petrol>>p[i].distance;
        Solution obj;
        cout<<obj.tour(p,n)<<endl;
    }
}

// } Driver Code Ends