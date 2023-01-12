#define pii pair<string,int>

class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        
        vector<int>ans;
        
        for(auto q: queries){
            int k = q[0];
            int trim = q[1];
            
            priority_queue<pii,vector<pii>,greater<pii>>pq;
            
            for(int j=0;j<nums.size();j++){               
                
                string num = nums[j];
                string temp="";
                
                for(int i=num.size()-trim;i<num.size();i++){
                    temp += num[i];
                }
                
                pq.push({temp,j});
            }
            
            while(!pq.empty() && k > 1){
                pq.pop();
                k--;
            }
            
            ans.push_back(pq.top().second);
        }
        
        return ans;
    }
};