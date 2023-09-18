class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        
        vector<pair<int,int>>rows;
        for(int i=0;i<mat.size();i++){
            int count=0;
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j] == 0){
                    break;
                }
                count++;
            }
            rows.push_back({count,i});
        }
        
        sort(rows.begin(),rows.end());
        vector<int>ans;
        
        int i=0;
        while(k--){
            ans.push_back(rows[i].second);
            i++;
        }
        return ans;
    }
};