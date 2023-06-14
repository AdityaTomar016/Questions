class Solution {
public:
    string getPermutation(int n, int k) {
        
        int fact=1;
        vector<int>nums;
        
        for(int i=1;i<n;i++){
            fact = fact*i;
        }
        
        for(int i=1;i<=n;i++){
            nums.push_back(i);
        }        
        
//coz we are considering 0 based indexing and 1234 will be our 0th permutation so bcoz of that the required permutation will be (k-1)th
        k = k-1;
        
        string ans = "";
        
        while(true){
            int currIdx = k/fact;
            ans += to_string(nums[currIdx]);
            
            nums.erase(nums.begin()+currIdx);
            
            if(nums.size() == 0){
                break;
            }
            
            k = k%fact;
            fact = fact/nums.size();
        }
        
        return ans;
    }
};