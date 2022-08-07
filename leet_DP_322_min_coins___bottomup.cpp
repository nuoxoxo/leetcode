class Solution {
public:
    int coinChange(vector<int>& coins, int amount)
    {
        vector<int> dp(amount + 1, amount + 1);
        int         i = 0;

        dp[0] = 0;
        while (++i < amount + 1)
        {
            for (int c: coins)
            {
                if (i >= c)
                    dp[i] = min(dp[i], dp[i - c] + 1);
            }
        }
        if (dp[amount] == amount + 1)
            return -1;
        return dp[amount];
    }
};
