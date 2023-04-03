class Solution {
public:
    int solve(int spell,vector<int>& potions, long long success){
        long long low=0,high=potions.size()-1;
        
        while(low < high){
            int mid = (low+high)/2;
            
            if((long long)potions[mid]*(long long)spell < success){
                low = mid+1;
            }
            else{
                high = mid;
            }
        }
        if(low == potions.size()-1 && (long long)potions[low]*(long long)spell < success){
            return 0;
        }
        return potions.size()-low;
    }
    vector<int> successfulPairs(vector<int >& spells, vector<int >& potions, long long success) {
        
        sort(potions.begin(),potions.end());
        vector<int>ans;
        
        for(int i=0;i<spells.size();i++){
            int count = solve(spells[i],potions,success);
            
            ans.push_back(count);
        }
        return ans;
    }
};