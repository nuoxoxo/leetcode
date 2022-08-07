class Solution {
public:
    int findLHS(vector<int>& nums)
    {
        map<int, int>   mp;
        int             res;

        res = 0;
        for (int n: nums)
            mp[n]++;
        for (int n: nums)
        {
            if (mp.find(n + 1) != mp.end())
                res = max(res, mp[n] + mp[n + 1]);
        }
        return res;
    }
};
