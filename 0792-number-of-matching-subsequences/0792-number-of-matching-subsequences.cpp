class Solution {
public:
    int solve(string& s, string& p, int n, int m)
{
    int j = 0;
    for(int i = 0; i < n; i++)
    {
        if(s[i] == p[j]) j++;
        if(j == m) return 1;
    }
    return 0;
}

int numMatchingSubseq(string s, vector<string>& words) {
    int n = words.size();
    int ans = 0;
    unordered_map<string, int> mp;
    for(int i = 0; i < n; i++)
    {
        if(mp.find(words[i]) != mp.end())
        {
            ans += mp[words[i]];
        }
        else
        {
            mp[words[i]] = solve(s, words[i], s.length(), words[i].length());
            ans += mp[words[i]];
        }
    }
    return ans;
}
};