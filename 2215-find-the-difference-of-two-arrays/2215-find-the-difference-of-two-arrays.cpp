class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int>s1,s2;
        
        for(auto i: nums1){
            s1.insert(i);
        }
        for(auto i: nums2){
            s2.insert(i);
        }
        
        vector<vector<int>>ans;
        
        vector<int>temp;
        for(auto i: s1){
            if(s2.find(i) == s2.end()){
                temp.push_back(i);
            }
        }
        ans.push_back(temp);
        
        temp.clear();
        for(auto i: s2){
            if(s1.find(i) == s1.end()){
                temp.push_back(i);
            }
        }
        ans.push_back(temp);
        
        return ans;
    }
};