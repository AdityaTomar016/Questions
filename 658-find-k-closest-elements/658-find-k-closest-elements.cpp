class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        
        vector<int>v;
        
        for(int i=0;i<arr.size();i++){
            pq.push({abs(arr[i]-x),arr[i]});
        }
        
        for(int i=0;i<k;i++){
            auto temp = pq.top();
            pq.pop();
            v.push_back(temp.second);
        }
        
        sort(v.begin(),v.end());
        
        
        return v;
    }
};