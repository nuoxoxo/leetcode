class Solution {
public:
    int coinChange(vector<int>& coins, int amount)
    {
        ++amount;

        int i = 0;
        int dp[amount];
        dp[0] = 0;
        sort(coins.begin(), coins.end());
        while (++i < amount)
        {
            dp[i] = 1e9;
            for (int c: coins)
            {
                if (i < c)
                    break;
                dp[i] = min(dp[i], dp[i - c] + 1);
            }
        }
        if (dp[amount - 1] == 1e9)
            return -1;
        return dp[amount - 1];
    }
};
