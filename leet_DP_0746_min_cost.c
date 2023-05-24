

int minCostClimbingStairs(int* cost, int costSize)
{
    int     dp[costSize  +1];
    int     p1, p2, i;

    dp[0] = 0;
    dp[1] = 0;
    i = 1;
    while (++i < costSize + 1)
    {
        p2 = dp[i - 2] + cost[i - 2];
        p1 = dp[i - 1] + cost[i - 1];
        dp[i] = p1 < p2 ? p1 : p2;
    }
    return dp[costSize];
}
