class Solution {
public:
    int integerBreak(int n)
    {
        if (n < 4)
            return n - 1;
        vector<int> dp(n + 1, 0);
        dp[2] = 1;
        int i = 2, j;
        while (++i < n + 1)
        {
            j = 0;
            while (++j < i / 2 + 1)
                dp[i] = max(max((i - j) * j, dp[i - j] * j), dp[i]);
        }
        return dp[n];
    }
};
