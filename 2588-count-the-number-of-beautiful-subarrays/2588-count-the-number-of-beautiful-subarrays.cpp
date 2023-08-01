class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        unordered_map<long long,long long>mp;
        long long xr = 0;
        long long count=0;
        mp[0] = 1;

        for(int i=0;i<nums.size();i++){
            xr = xr^nums[i];

            long long tar = xr;

            if(mp.find(tar) != mp.end()){
                count += mp[tar];
            }
            mp[xr]++;
    }

    return count;
    }
};