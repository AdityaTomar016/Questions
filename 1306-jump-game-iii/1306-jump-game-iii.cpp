class Solution {
public:
    bool solve(int i,int n, vector<int>&arr,vector<int>&vis){
        
        if(i<0 || i>= n || vis[i]){
            return false;
        }
        
        int curr = arr[i];
        
        if(curr == 0){
            return true;
        }
        
        vis[i]  = 1;
        
        return solve(i+curr,n,arr,vis) || solve(i-curr,n,arr,vis);
    }
    bool canReach(vector<int>& arr, int start) {
        
        int n = arr.size();
        vector<int>vis(n,0);
        return solve(start,n,arr,vis);
    }
};