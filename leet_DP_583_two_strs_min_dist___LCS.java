class Solution {
    public int minDistance(String s1, String s2)
    {
        int     n1 = s1.length();
        int     n2 = s2.length();
        int[][] dp = new int[n1 + 1][n2 + 1];
        int     i = 0, j;

        while (++i < n1 + 1)
        {
            j = 0;
            while (++j < n2 + 1)
            {
                if (s1.charAt(i - 1) == s2.charAt(j - 1))
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return n1 + n2 - 2 * dp[n1][n2];
    }
}
