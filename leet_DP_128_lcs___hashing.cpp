class Solution {
public:
    int longestConsecutive(vector<int>& nums)
    {
        vector<int>     dp(len, 1);
        int             len, i, j, tmp, dif;

        len = (int) nums.size();
        if (len < 2)
            return (len);
        sort(nums.begin(), nums.end());
        i = 0;
        while (++i < len)
        {
            dif = nums[i] - nums[i - 1];
            if (dif < 2)
                dp[i] = dp[i - 1] + dif;
        }
        return (*std::max_element(dp.begin(), dp.end()));
    }
};
