//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int isItPossible(string S, string T, int M, int N) {

        int i = 0;

        int j = 0;

        while(i<M && j<N){

            while(S[i]=='#' && i<M){

                i++;

            }

            while(T[j]=='#' && j<N){

                j++;

            }

            if(S[i]!=T[j]){

                return 0;

            }

            else{

                if(S[i]=='A' && T[j]=='A'){

                    if(i<j){

                        return 0;

                    }

                }

                if(S[i]=='B' && T[j]=='B'){

                    if(i>j){

                        return 0;

                    }

                }

                i++;

                j++;

            }

        }

        while(i<M){

            if(S[i]!='#'){

                return 0;

            }

            i++;

        }

        while(j<N){

            if(T[j]!='#'){

                return 0;

            }

            j++;

        }

        return 1;

    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S, T;
        cin >> S >> T;
        int M = S.length(), N = T.length();
        Solution ob;
        cout << ob.isItPossible(S, T, M, N);
        cout << "\n";
    }
}
// } Driver Code Ends