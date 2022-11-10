class Solution {
public:
    int minSetSize(vector<int>& arr) {
        
        unordered_map<int,int>mp;
        vector<int>v;
        
        int count=0;
        int ans=0;
        
        for(auto i: arr){
            mp[i]++;
        }
        
    

        for(auto i: mp){
            v.push_back(i.second);
        }
           
        sort(v.begin(),v.end(),greater<int>());
        
        int i=0;
        while(count < arr.size()/2){
            count += v[i++];
            ans++;
        }
        
        return ans;
    }
};