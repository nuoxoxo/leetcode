class Solution {
    public int minCostClimbingStairs(int[] cost)
    {
        int     len, p1, p2, i;
        int[]   dp;

        len = cost.length;
        dp = new int[len + 1];
        dp[0] = 0;
        dp[1] = 0;
        i = 1;
        while (++i < len + 1)
        {
            p1 = cost[i - 1] + dp[i - 1];
            p2 = cost[i - 2] + dp[i - 2];
            dp[i] = p1 < p2 ? p1 : p2;
        }
        return dp[len];
    }
}
