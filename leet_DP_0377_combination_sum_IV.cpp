class Solution {
public:
    int combinationSum4(vector<int>& nums, int target)
    {
        vector<unsigned long long>  dp(target + 1, 0); // or unsigned int
        int                         i;

        dp[0] = 1;
        i = 0;
        while (++i < target + 1)
        {
            for (int n: nums)
            {
                if (i - n > -1)
                {
                    dp[i] += dp[i - n];
                }
            }
        }
        return dp[target];
    }
};
