class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
        vector<vector<int>>ans;
        int n=1;
        vector<int>prev;
        bool flag=true;
        
        for(int i=0;i<numRows;i++){
            
            vector<int>ds(n,1);
            // if(flag){
            //     ans.push_back(ds);
            //     flag=false;
            // }
            
            for(int k=1;k<n-1;k++){
                ds[k] = prev[k-1] + prev[k];
            }
            
            prev = ds;
            ans.push_back(ds);
            n++;
        }
        
        return ans;
    }
};