class Solution {
    public int fib(int n)
    {
        int[]   dp;
        int     i;

        if (n < 2)
            return n;
        dp = new int[n + 1];
        dp[0] = 0;
        dp[1] = 1;
        i = 1;
        while (++i < n + 1)
            dp[i] = dp[i - 2] + dp[i - 1];
        return dp[i - 1];
    }
}
