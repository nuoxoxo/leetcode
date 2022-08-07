class Solution {
public:
    int findLHS(vector<int>& nums)
    {
        int     len = nums.size();

        if (len < 2)
            return 0;
        if (len == 2)
            return abs(nums[0] - nums[1]) == 1 ? 2 : 0;

        map<int, int>   mp;
        int             res;

        for (int n: nums)
            mp[n]++;
        res = 0;
        for (int n: nums)
        {
            if (mp.find(n + 1) != mp.end())
                res = max(res, mp[n] + mp[n + 1]);
        }
        return res;
    }
};
