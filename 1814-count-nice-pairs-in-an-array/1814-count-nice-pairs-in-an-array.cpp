class Solution {
public:
    int rev(int num){
        int r=0;
        
        while(num>0){
            int last = num%10;
            r = r*10 + last;
            num = num/10;
        }
        
        return r;
    }
    int countNicePairs(vector<int>& nums) {
        
        int n = nums.size();
        int count=0;
        
        int mod = 1e9+7;
        map<int,int>mp;
        
        for(int i=0;i<n;i++){
            nums[i] = (nums[i]-rev(nums[i]));
            
            if(mp[nums[i]] > 0){
                count = (count+mp[nums[i]])%mod;
            }
            
            mp[nums[i]]++;
        }
        
        return count;
    }
};

// nums[i]-rev[i] == nums[j]-rev[j]